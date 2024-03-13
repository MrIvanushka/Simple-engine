#ifndef REACTIMPL_MESHCOLLIDER_H
#define REACTIMPL_MESHCOLLIDER_H

#include <reactphysics3d/reactphysics3d.h>
#include <glm/glm.hpp>

#include "Collider.h"

namespace ReactPhysicsImpl
{

    class MeshCollider : public ReactPhysicsImpl::Collider
    {
    public:
        MeshCollider(std::shared_ptr<Engine::GameObject> obj) : Collider(obj) { }
    };

}

#endif //REACTIMPL_MESHCOLLIDER_H