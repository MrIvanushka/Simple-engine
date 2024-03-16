#ifndef REACTIMPL_SPHERECOLLIDER_H
#define REACTIMPL_SPHERECOLLIDER_H

#include <reactphysics3d/reactphysics3d.h>
#include <glm/glm.hpp>

#include "Collider.h"

namespace ReactPhysicsImpl
{

class SphereCollider : public ReactPhysicsImpl::Collider
{
private:
    reactphysics3d::SphereShape* _shape;

    float _radius = 1;
public:
    SphereCollider(std::shared_ptr<Engine::GameObject> obj) : Collider(obj) { }

    void initialize(reactphysics3d::Collider* collider, reactphysics3d::SphereShape* shape)
    {
        _shape = shape;
        _shape->setRadius(_radius);
        Collider::initialize(collider);
    }

    void setRadius(float value) { if (_shape) _shape->setRadius(value); else _radius = value; }

    float radius() const { _shape->getRadius(); }
};

}

#endif //REACTIMPL_SPHERECOLLIDER_H