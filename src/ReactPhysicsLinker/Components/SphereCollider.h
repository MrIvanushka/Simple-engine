#ifndef REACTIMPL_SPHERECOLLIDER_H
#define REACTIMPL_SPHERECOLLIDER_H

#include <reactphysics3d/reactphysics3d.h>
#include <glm/glm.hpp>

#include "Collider.h"

namespace ReactPhysicsImpl
{

    class SphereCollider : public ReactPhysicsImpl::Collider
    {
    public:
        SphereCollider(std::shared_ptr<Engine::GameObject> obj) : Collider(obj) { }
    };

}

#endif //REACTIMPL_SPHERECOLLIDER_H