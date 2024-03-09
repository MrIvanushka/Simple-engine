#ifndef ENGINE_GAMEOBJECT_H
#define ENGINE_GAMEOBJECT_H

#include <set>
#include <memory>
#include <stdexcept>

#include "Transform.h"

namespace Engine
{

class Component;

class GameObject final
{
private:
    bool                                    _isActive = true;
    std::shared_ptr<Transform>              _transform;
    std::set<std::shared_ptr<Component>>    _components;
public:
    GameObject(std::shared_ptr<Transform> transform) : _transform(transform) {}

    void start();
    void update(float deltaTime);
    void render();

    void setActive(bool value);

    bool activeSelf() const { return _isActive; }
    std::shared_ptr<Transform> transform() const { return _transform; }

    template<typename T>
    void addComponent()
    {
        if (this->getComponent<T>() != nullptr)
            throw std::logic_error("GameObject already contains component that you are trying to add.");

        this->_components.insert(std::make_shared<T>(this));
    }
    template<typename T>
    T* getComponent() const
    {
        for (Component* component : _components)
        {
            T* typedComponent = dynamic_cast<T*>(component);
            if (typedComponent != nullptr)
                return typedComponent;
        }
        return nullptr;
    }
};

}

#endif //ENGINE_GAMEOBJECT_H
