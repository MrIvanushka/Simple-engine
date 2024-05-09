#ifndef REACTIMPL_COLLIDER_H
#define REACTIMPL_COLLIDER_H

#include <reactphysics3d/reactphysics3d.h>
#include <glm/glm.hpp>

#include "Components/Collider.h"

namespace ReactPhysicsImpl
{

    class ReactCollider : public Engine::ICollider
    {
    private:
        reactphysics3d::Collider* _physicObject = nullptr;

    public:
        ReactCollider(reactphysics3d::Collider* physicObject) : _physicObject(physicObject) { }

        void setIsTrigger(bool value) override { _physicObject->setIsTrigger(value); }

        bool isTrigger() const override { return _physicObject->getIsTrigger(); }
    };

}

#endif //REACTIMPL_COLLIDER_H