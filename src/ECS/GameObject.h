#ifndef ENGINE_GAMEOBJECT_H
#define ENGINE_GAMEOBJECT_H

#include <set>
#include <memory>
#include <stdexcept>

#include "Transform.h"
#include "Input.h"

namespace Engine
{

class Component;

class GameObject final : public  std::enable_shared_from_this<GameObject>
{
private:
    bool                                    _isActive = true;
    std::shared_ptr<Transform>              _transform;
    std::shared_ptr<Input>                  _input;
    std::set<std::shared_ptr<Component>>    _components;
public:
    GameObject(std::shared_ptr<Transform> transform, std::shared_ptr<Input> input) : 
        _transform(transform), _input(input) {}

    void start();
    void update(float deltaTime);
    void render();

    void setActive(bool value);

    bool                        activeSelf() const { return _isActive; }
    std::shared_ptr<Transform>  transform() const { return _transform; }
    std::shared_ptr<Input>      input() const { return _input; }

    template<typename T>
    void addComponent()
    {
        if (this->getComponent<T>() != nullptr)
            throw std::logic_error("GameObject already contains component that you are trying to add.");

        this->_components.insert(std::make_shared<T>(shared_from_this()));
    }
    template<typename T>
    std::shared_ptr<T> getComponent() const
    {
        for (auto component : _components)
        {
            std::shared_ptr<T> typedComponent = std::dynamic_pointer_cast<T>(component);

            if (typedComponent != nullptr)
                return typedComponent;
        }
        return nullptr;
    }
};

}

#endif //ENGINE_GAMEOBJECT_H
