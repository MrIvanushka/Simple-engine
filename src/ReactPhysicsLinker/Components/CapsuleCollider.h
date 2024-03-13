#ifndef REACTIMPL_CAPSULECOLLIDER_H
#define REACTIMPL_CAPSULECOLLIDER_H

#include <reactphysics3d/reactphysics3d.h>
#include <glm/glm.hpp>

#include "Collider.h"

namespace ReactPhysicsImpl
{

    class CapsuleCollider : public ReactPhysicsImpl ::Collider
    {
    public:
        CapsuleCollider(std::shared_ptr<Engine::GameObject> obj) : Collider(obj) { }
    };

}

#endif //REACTIMPL_CAPSULECOLLIDER_H