#ifndef ENGINE_COMPONENT_H
#define ENGINE_COMPONENT_H

#include <set>
#include <memory>

#include "GameObject.h"

namespace Engine
{

class Component
{
protected:
    std::shared_ptr<GameObject> _gameObject;
    bool                        _enabled;
public:
    Component(std::shared_ptr<GameObject> object, bool enabledOnStart = true)
    {
        _enabled = enabledOnStart;
        _gameObject = object;
    }
    virtual ~Component() = default;

    virtual void                start() {}
    virtual void                update(float deltaTime) {}
    virtual void                render() {}
    std::shared_ptr<GameObject> getGameObject() { return _gameObject; }

    bool isEnabled()
    {
        return _enabled && _gameObject->activeSelf();
    }

    template<typename T>
    T* getComponent()
    {
        return _gameObject->getComponent<T>();
    }
};

}

#endif //ENGINE_COMPONENT_H
