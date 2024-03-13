#include "GameObject.h"
#include "Component.h"

using namespace Engine;

void GameObject::start()
{
    for (auto component : _components) {
        component->start();
    }
}

void GameObject::setActive(bool value)
{
    if (value != _isActive)
    {
        _isActive = value;
        _transform->handleActivityChange(value);

        for (auto component : _components)
            component->switchEnabledByParent(value);
    }
}

void GameObject::update(float deltaTime)
{
    if(_isActive) 
    {
        for (auto component : _components)
        {
            if (component->isEnabled())
                component->update(deltaTime);
        }
    }
}

void GameObject::render()
{
    if(_isActive)
    {
        for (auto component : _components) {
            if (component->isEnabled())
                component->render();
        }
    }
}
