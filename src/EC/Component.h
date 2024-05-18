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
    std::shared_ptr<Input>      _input;
public:
    friend class Entity;
    friend class GameObject;

    Component(std::shared_ptr<GameObject> object, std::shared_ptr<Input> input, bool enabledOnStart = true)
    {
        _enabled = enabledOnStart;
        _gameObject = object;
        _input = input;
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

    bool isEnabled() const
    {
        return _enabled;
    }

    std::shared_ptr<Transform> transform() const { return _gameObject->transform(); }

    std::shared_ptr<GameObject> gameObject() const { return _gameObject; }

    template<typename T>
    std::shared_ptr<T> getComponent() const { return _gameObject->getComponent<T>(); }
protected:
    std::shared_ptr<Input> input() const { return _input; }
private:
    void switchEnabledByParent(bool enabled)
    {
        if (enabled && !_enabled)
            onEnable();
        else if (!enabled && _enabled)
            onDisable();
    }

    virtual void onEnable() {}
    virtual void onDisable() {}
    virtual void start() {}
    virtual void update(float deltaTime) {}
    virtual void render() {}
};

}

#endif //ENGINE_COMPONENT_H
