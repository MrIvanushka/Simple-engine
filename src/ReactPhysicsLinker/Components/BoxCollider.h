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
    reactphysics3d::CollisionShape* _shape;
public:
    BoxCollider(std::shared_ptr<Engine::GameObject> obj) : Collider(obj) { }

    void initialize(reactphysics3d::Collider* physicObject) override
    {
        Collider::initialize(physicObject);
    }
};

}

#endif //REACTIMPL_BOXCOLLIDER_H