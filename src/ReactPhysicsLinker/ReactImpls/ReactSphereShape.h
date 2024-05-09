#ifndef REACTIMPL_SPHERECOLLIDER_H
#define REACTIMPL_SPHERECOLLIDER_H

#include <reactphysics3d/reactphysics3d.h>
#include <glm/glm.hpp>

#include "Components/SphereCollider.h"

namespace ReactPhysicsImpl
{

class ReactSphereShape : public Engine::ISphereShape
{
private:
    reactphysics3d::SphereShape* _shape = nullptr;

public:
    ReactSphereShape(reactphysics3d::SphereShape* shape) : _shape(shape) { }

    void setRadius(float value) override { _shape->setRadius(value); }

    float radius() const override { return _shape->getRadius(); }
};

}

#endif //REACTIMPL_SPHERECOLLIDER_H