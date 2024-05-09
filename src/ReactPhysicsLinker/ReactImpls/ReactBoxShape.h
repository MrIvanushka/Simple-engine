#ifndef REACTIMPL_BOXCOLLIDER_H
#define REACTIMPL_BOXCOLLIDER_H

#include <reactphysics3d/reactphysics3d.h>
#include <glm/glm.hpp>

#include "Components/BoxCollider.h"

namespace ReactPhysicsImpl
{

class ReactBoxShape : public Engine::IBoxShape
{
private:
    reactphysics3d::BoxShape* _shape = nullptr;

public:
    ReactBoxShape(reactphysics3d::BoxShape* shape) : _shape(shape)
    { }

    void setHalfExtents(glm::vec3 value) override
    { 
        _shape->setHalfExtents(reactphysics3d::Vector3(value.x, value.y, value.z)); 
    }

    glm::vec3 halfExtents() const override
    { 
        return glm::vec3(_shape->getHalfExtents().x, _shape->getHalfExtents().y, _shape->getHalfExtents().z);
    }
};

}

#endif //REACTIMPL_BOXCOLLIDER_H