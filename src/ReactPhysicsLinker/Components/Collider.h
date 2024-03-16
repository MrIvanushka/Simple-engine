#ifndef REACTIMPL_COLLIDER_H
#define REACTIMPL_COLLIDER_H

#include <reactphysics3d/reactphysics3d.h>
#include <glm/glm.hpp>

#include "Component.h"

namespace ReactPhysicsImpl
{

    class Collider : public Engine::Component
    {
    protected:
        reactphysics3d::Collider* _physicObject;
    private:
        bool _isTrigger = false;
    public:
        Collider(std::shared_ptr<Engine::GameObject> obj) : Component(obj) { }

        virtual void initialize(reactphysics3d::Collider* physicObject)
        {
            _physicObject = physicObject;
            _physicObject->setIsTrigger(_isTrigger);
        }

        void setIsTrigger(bool value) { if (_physicObject != nullptr) _physicObject->setIsTrigger(value); else _isTrigger = isTrigger; }

        bool isTrigger() const { if (_physicObject != nullptr) return _physicObject->getIsTrigger(); else return _isTrigger; }
    };

}

#endif //REACTIMPL_COLLIDER_H