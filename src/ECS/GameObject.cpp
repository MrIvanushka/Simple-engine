#include "GameObject.h"
#include "Component.h"

using namespace Engine;

void Entity::start()
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

void Entity::update(float deltaTime)
{
    if(activeSelf()) 
    {
        for (auto component : _components)
        {
            if (component->isEnabled())
                component->update(deltaTime);
        }
    }
}

void Entity::render()
{
    if(activeSelf())
    {
        for (auto component : _components) {
            if (component->isEnabled())
                component->render();
        }
    }
}
