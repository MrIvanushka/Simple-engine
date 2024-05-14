#ifndef ENGINE_SPHERECOLLIDER_H
#define ENGINE_SPHERECOLLIDER_H

#include <glm/glm.hpp>

#include "Collider.h"

namespace Engine
{

class ISphereShape
{
public:
    virtual ~ISphereShape() = default;

    virtual void setRadius(float radius) = 0;

    virtual float radius() const = 0;
};

class SphereCollider : public Collider
{
private:
    std::shared_ptr<ISphereShape> _shape = nullptr;

    float _radius = 1;
public:
    SphereCollider(std::shared_ptr<Engine::GameObject> obj, std::shared_ptr<Input> input) : Collider(obj, input) { }

    void initialize(std::shared_ptr<ICollider> collider, std::shared_ptr<ISphereShape> shape)
    {
        _shape = shape;
        _shape->setRadius(_radius);
        Collider::initialize(collider);
    }

    void setRadius(float value) { if (_shape) _shape->setRadius(value); else _radius = value; }

    float radius() const { _shape->radius(); }
};

}

#endif //ENGINE_SPHERECOLLIDER_H