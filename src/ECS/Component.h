#ifndef ENGINE_COMPONENT_H
#define ENGINE_COMPONENT_H

#include <set>
#include <memory>

#include "GameObject.h"

namespace Engine
{

class Component
{
private:
    std::shared_ptr<GameObject> _gameObject;
    bool                        _enabled;
public:
    Component(std::shared_ptr<GameObject> object, bool enabledOnStart = true)
    {
        _enabled = enabledOnStart;
        _gameObject = object;
    }
    virtual ~Component() = default;

    virtual void                onEnable() {}
    virtual void                onDisable() {}
    virtual void                start() {}
    virtual void                update(float deltaTime) {}
    virtual void                render() {}
    std::shared_ptr<GameObject> gameObject() { return _gameObject; }

    void switchEnabled(bool enabled)
    {
        if (enabled && !_enabled)
        {
            _enabled = true;
            onEnable();
        }
        else if (!enabled && _enabled)
        {
            _enabled = false;
            onDisable();
        }

    }

    void switchEnabledByParent(bool enabled)
    {
        if (enabled && !_enabled)
            onEnable();
        else if (!enabled && _enabled)
            onDisable();
    }

    bool isEnabled()
    {
        return _enabled;
    }

    template<typename T>
    std::shared_ptr<T> getComponent()
    {
        return _gameObject->getComponent<T>();
    }
};

}

#endif //ENGINE_COMPONENT_H
