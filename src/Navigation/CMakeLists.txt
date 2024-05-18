project(Navigation)

add_library(${PROJECT_NAME} STATIC
	NavMesh.cpp
	NavMesh.h
	NavMeshGenerator.h
	polypartition.cpp
	polypartition.h
	Struct_utilities.cpp
	Struct_utilities.h
)

target_link_libraries(${PROJECT_NAME}
	PUBLIC EC
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ../EC
)
