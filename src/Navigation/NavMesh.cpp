#include "NavMesh.h"

#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <stdexcept>
#include <float.h>

/* NavMeshSurface */

/* Constructor */

NavMeshSurface::NavMeshSurface(const std::vector<TPPLPoint>& border) {

    m_polygons.emplace_back(TPPLPoly(border, false, TPPL_ORIENTATION_CCW));
    
    update_grid();
}

/* Insertion of new (hole) areas */
#include <iostream>
void NavMeshSurface::add_area(const std::vector<TPPLPoint>& border){

    if (expansion_called) { throw std::runtime_error("New areas cannot be added after expansion called"); }

    // Validity check
    if (border.size() < 3) throw std::runtime_error("Invalid area: polygon count is lower than 2");
            
    for ( size_t i = 0, j = border.size() - 1 ; i < border.size() ; j = i++ ){
        TPPLPoint p1 = border[i], p2 = border[j];

        for (auto polygon : m_polygons){
            if (polygon.intersects_with_line(p1, p2))
                throw std::runtime_error("Invalid area: intersection with border of size " +std::to_string(polygon.GetNumPoints()) + " points "
                + std::to_string(p1.x) + " " + std::to_string(p1.y) + "; " + std::to_string(p2.x) + " " + std::to_string(p2.y));
            if(!(m_polygons.begin()->contains_point(p1)))
                throw std::runtime_error("Invalid area: point away from border " +std::to_string(polygon.GetNumPoints()));
        }
    }

    m_polygons.emplace_back(TPPLPoly(border, true, TPPL_ORIENTATION_CW));

    update_grid();
}

void NavMeshSurface::expand(const NavMeshSurface& surface) {
    expansion_called = true;

    for (auto it = surface.outpolys.begin(); it != surface.outpolys.end(); ++it) {
        this->outpolys.emplace_back(*it);
    }

    for (auto it = ++surface.m_polygons.begin(); it != surface.m_polygons.end(); ++it) {
        this->m_polygons.emplace_back(*it);
    }

    update_grid();
}

/* Constructing path */

std::vector<TPPLPoint> NavMeshSurface::reconstruct_path(const std::unordered_map<TPPLPoly_it, TPPLPoly_it>& came_from, TPPLPoly_it& current, const TPPLPoint& start, const TPPLPoint& end){

    std::vector<TPPLPoint> total_path;
    total_path.push_back(end);
    while (came_from.contains(current)){
        total_path.push_back(TPPLPoint((poly_grid.at(current).at(came_from.at(current)).line[0].x + poly_grid.at(current).at(came_from.at(current)).line[1].x) / 2,
        (poly_grid.at(current).at(came_from.at(current)).line[0].y + poly_grid.at(current).at(came_from.at(current)).line[1].y) / 2));
        
        current = came_from.at(current);
    }
    total_path.push_back(start);

    std::reverse(total_path.begin(), total_path.end());

    std::vector<TPPLPoint> path;

    path.push_back(total_path[0]);

    size_t next_index = 0;

        for (size_t j = next_index + 1; j < total_path.size(); ++j) {
            bool hasIntersections = false;

            for (auto polygon : m_polygons) {
                if (polygon.intersects_with_line(total_path[next_index], total_path[j])) {
                    hasIntersections = true;
                    break;
                }
            }
            if(!hasIntersections)
            {
                next_index = j;
                path.push_back(total_path[next_index]);
            }
        }

    return path;
}

[[nodiscard]] NavMeshPath NavMeshSurface::get_path(const TPPLPoint& start, const TPPLPoint& end){

    TPPLPoly_it start_poly = outpolys.begin(), end_poly = outpolys.begin();

    for (auto polygon = outpolys.begin(); polygon != outpolys.end(); ++polygon) {
        if (polygon->contains_point(start)) start_poly = polygon;
        if (polygon->contains_point(end)) end_poly = polygon;
    }

    // A* algorithm
    // https://en.wikipedia.org/wiki/A*_search_algorithm

    std::priority_queue<Node> open_set;
    open_set.push(Node(start_poly, 0));

    std::unordered_map<TPPLPoly_it, TPPLPoly_it> came_from;

    std::unordered_map<TPPLPoly_it, double> g_score;
    std::unordered_map<TPPLPoly_it, double> f_score;

    for (auto polygon = outpolys.begin(); polygon != outpolys.end(); ++polygon) {
        g_score[polygon] = DBL_MAX;
        f_score[polygon] = DBL_MAX;
    }
    g_score[start_poly] = 0;
    f_score[start_poly] = TPPLPoint::distance(centers.at(start_poly), centers.at(end_poly));

    std::vector<TPPLPoly_it> open_set_hash;
    open_set_hash.push_back(start_poly);

    while (!open_set.empty()) {

        TPPLPoly_it current = open_set.top().poly;
        open_set.pop();

        open_set_hash.erase(std::find(open_set_hash.begin(), open_set_hash.end(), current));

        if (current == end_poly){
            return NavMeshPath(reconstruct_path(came_from, end_poly, start, end));
        }

        for (auto neighbour = poly_grid[current].begin(); neighbour != poly_grid[current].end(); ++neighbour) {
            double temp_g_score = g_score.at(current) + TPPLPoint::distance(centers.at(neighbour->first), centers.at(current));

            if (temp_g_score < g_score[neighbour->first]) {
                came_from[neighbour->first] = current;
                g_score[neighbour->first] = temp_g_score;
                f_score[neighbour->first] = temp_g_score + TPPLPoint::distance(centers.at(neighbour->first), centers.at(end_poly));

                if (std::find(open_set_hash.begin(), open_set_hash.end(), neighbour->first) == open_set_hash.end()){
                    open_set.push(Node(neighbour->first, f_score.at(neighbour->first)));
                    open_set_hash.push_back(neighbour->first);
                }
            }
        }

    }
    
    // default output
    std::vector<TPPLPoint> path;
    path.push_back(start);
    path.push_back(end);
    return NavMeshPath(path);
}

/* Building grid */

void NavMeshSurface::update_grid(){

    poly_grid.clear();
    centers.clear();

    //  decomposition
    TPPLPartition handler;
    if (!expansion_called) { outpolys.clear(); handler.ConvexPartition_HM(&m_polygons, &outpolys); }
    //handler.Triangulate_EC(&inpolys, &outpolys);
    
    //  building grid of neighbour polygons
    for (auto current_poly = outpolys.begin(); current_poly != outpolys.end(); ++current_poly) {

        TPPLPoint current_center = current_poly->centroid();

        centers[current_poly] = current_center;

        for (auto it = std::next(current_poly, 1); it != outpolys.end(); ++it){

            //  then find common sides
            std::vector<TPPLPoint> common_points;
            for (long i = 0; i < current_poly->GetNumPoints(); ++i){
                for (long j = 0; j < (*it).GetNumPoints(); ++j){
                    if ((*current_poly)[i] == (*it)[j]){
                        common_points.push_back(TPPLPoint((*current_poly)[i].x, (*current_poly)[i].y));
                    }
                }
            }

            if (common_points.size() == 2){
                poly_grid[current_poly][it].line = common_points;
                poly_grid[it][current_poly].line = common_points;
            }

        }
    }
}

/* NavMeshPath */

NavMeshPath::NavMeshPath(){}

NavMeshPath::NavMeshPath(const std::vector<TPPLPoint>& points){
    path = points;
}

const TPPLPoint& NavMeshPath::operator[](size_t index) const{
    return path[index];
}

const std::vector<TPPLPoint>& NavMeshPath::get_points() const{
    return path;
}
