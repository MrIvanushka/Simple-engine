#ifndef ENGINE_COLLIDER_H
#define ENGINE_COLLIDER_H

#include <glm/glm.hpp>

#include "../Component.h"

namespace Engine
{

    class ICollider
    {
    public:
        virtual ~ICollider() = default;

        virtual void setIsTrigger(bool value) = 0;

        virtual bool isTrigger() const = 0;
    };

    class Collider : public Engine::Component
    {
    private:
        std::shared_ptr<ICollider> _physicObject = nullptr;

        bool _isTrigger = false;
    public:
        Collider(std::shared_ptr<Engine::GameObject> obj, std::shared_ptr<Input> input) : Component(obj, input) { }

        void setIsTrigger(bool value) { if (_physicObject != nullptr) _physicObject->setIsTrigger(value); else _isTrigger = value; }

        bool isTrigger() const { if (_physicObject != nullptr) return _physicObject->isTrigger(); else return _isTrigger; }

    protected:
        void initialize(std::shared_ptr<ICollider> physicObject)
        {
            _physicObject = physicObject;

            _physicObject->setIsTrigger(_isTrigger);
        }
    };

}

#endif //ENGINE_COLLIDER_H