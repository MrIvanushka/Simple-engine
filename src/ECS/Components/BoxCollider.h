#ifndef ENGINE_BOXCOLLIDER_H
#define ENGINE_BOXCOLLIDER_H

#include <glm/glm.hpp>

#include "Collider.h"

namespace Engine
{

class IBoxShape
{
public:
    virtual ~IBoxShape() = default;

    virtual void setHalfExtents(glm::vec3 halfExtents) = 0;

    virtual glm::vec3 halfExtents() const = 0;
};

class BoxCollider : public Collider
{
private:
    std::shared_ptr<IBoxShape> _shape = nullptr;

    glm::vec3 _halfExtents;
public:
    BoxCollider(std::shared_ptr<GameObject> obj) : Collider(obj) { }

    void initialize(std::shared_ptr<ICollider> collider, std::shared_ptr<IBoxShape> shape)
    {
        _shape = shape;
        _shape->setHalfExtents(_halfExtents);
        Collider::initialize(collider);
    }

    void setHalfExtents(glm::vec3 value) { 
        if (_shape)
            _shape->setHalfExtents(value);
        else
            _halfExtents = value;
    }

    glm::vec3 halfExtents() const { if (_shape != nullptr) return _shape->halfExtents(); else return _halfExtents; }
};

}

#endif //ENGINE_BOXCOLLIDER_H