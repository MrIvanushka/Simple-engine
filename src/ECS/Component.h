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
    friend class Entity;

    Component(std::shared_ptr<GameObject> object, bool enabledOnStart = true)
    {
        _enabled = enabledOnStart;
        _gameObject = object;
    }
    virtual ~Component() = default;

    void switchEnabled(bool enabled)
    {
        if (enabled && !_enabled)
        {
            _enabled = true;
            
            if (_gameObject->activeSelf())
                onEnable();
        }
        else if (!enabled && _enabled)
        {
            _enabled = false;

            if(_gameObject->activeSelf())
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

    bool isEnabled() const
    {
        return _enabled;
    }

    std::shared_ptr<Transform> transform() const { return _gameObject->transform(); }

    template<typename T>
    std::shared_ptr<T> getComponent() const { return _gameObject->getComponent<T>(); }
private:
    virtual void onEnable() {}
    virtual void onDisable() {}
    virtual void start() {}
    virtual void update(float deltaTime) {}
    virtual void render() {}
};

}

#endif //ENGINE_COMPONENT_H
