#ifndef REACTIMPL_BOXCOLLIDER_H
#define REACTIMPL_BOXCOLLIDER_H

#include <reactphysics3d/reactphysics3d.h>
#include <glm/glm.hpp>

#include "Collider.h"

namespace ReactPhysicsImpl
{

class BoxCollider : public ReactPhysicsImpl::Collider
{
private:
    reactphysics3d::BoxShape* _shape;

    glm::vec3 _halfExtents;
public:
    BoxCollider(std::shared_ptr<Engine::GameObject> obj) : Collider(obj) { }

    void initialize(reactphysics3d::Collider* collider, reactphysics3d::BoxShape* shape)
    {
        _shape = shape;
        _shape->setHalfExtents(reactphysics3d::Vector3(_halfExtents.x, _halfExtents.y, _halfExtents.z));
        Collider::initialize(collider);
    }

    void setHalfExtents(glm::vec3 value) { 
        if (_shape)
            _shape->setHalfExtents(reactphysics3d::Vector3(value.x, value.y, value.z)); 
        else
            _halfExtents = value;
    }

    glm::vec3 halfExtents() const { _shape->getHalfExtents(); }
};

}

#endif //REACTIMPL_BOXCOLLIDER_H