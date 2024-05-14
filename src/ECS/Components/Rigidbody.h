#ifndef ENGINE_RIGIDBODY_H
#define ENGINE_RIGIDBODY_H

#include <glm/glm.hpp>

#include "../Component.h"

namespace Engine
{

enum RigidbodyType
{
    RB_KINEMATIC,
    RB_DYNAMIC,
    RB_STATIC
};

class IRigidbody
{
public:
    virtual ~IRigidbody() = default;

    virtual void setType(RigidbodyType type) = 0;
    virtual void setMass(float mass) = 0;
    virtual void setLinearLockAxisFactor(glm::vec3 axisFactor) = 0;
    virtual void setAngularLockAxisFactor(glm::vec3 axisFactor) = 0;

    virtual void switchGravity(bool enabled) = 0;

    virtual void setVelocity(glm::vec3 velocity) = 0;
    virtual void setAngularVelocity(glm::vec3 angularVelocity) = 0;

    virtual RigidbodyType    type()                  const = 0;
    virtual float            mass()                  const = 0;
    virtual bool             gravityEnabled()        const = 0;
    virtual glm::vec3        linearLockAxisFactor()  const = 0;
    virtual glm::vec3        angularLockAxisFactor() const = 0;
    virtual glm::vec3        velocity()              const = 0;
    virtual glm::vec3        angularVelocity()       const = 0;
    virtual glm::vec3        position()              const = 0;
    virtual glm::quat        orientation()           const = 0;
};

class Rigidbody : public Component
{
private:
    std::shared_ptr<IRigidbody> _physicObject = nullptr;

    RigidbodyType _type = RB_DYNAMIC;

    float _mass = 100;
    bool _useGravity = true;

    glm::vec3 _linearLockAxisFactor = glm::vec3();
    glm::vec3 _angularLockAxisFactor = glm::vec3();
public:
    Rigidbody(std::shared_ptr<GameObject> obj, std::shared_ptr<Input> input) : Component(obj, input) { }

    void initialize(std::shared_ptr<IRigidbody> physicObject)
    {
        _physicObject = physicObject;

        _physicObject->setType(_type);
        //_physicObject->setMass(_mass);
        //_physicObject->setGravityEnabled(_useGravity);
        //_physicObject->setLinearLockAxisFactor(_linearLockAxisFactor);
        //_physicObject->setAngularLockAxisFactor(_angularLockAxisFactor);
    }

    void initializeType(RigidbodyType type) { if (_physicObject == nullptr) _type = type; else _physicObject->setType(type); }
    void initializeMass(float mass) { if (_physicObject == nullptr) _mass = mass; else _physicObject->setMass(mass); }

    void setLinearLockAxisFactor(glm::vec3 axisFactor);
    void setAngularLockAxisFactor(glm::vec3 axisFactor);

    void switchGravity(bool enabled) { if (_physicObject == nullptr) _useGravity = enabled; else _physicObject->switchGravity(enabled); }

    void setVelocity(glm::vec3 velocity);
    void setAngularVelocity(glm::vec3 angularVelocity);

    RigidbodyType type()                  const { return _physicObject->type(); }
    float         mass()                  const { return _physicObject->mass(); }
    bool          gravityEnabled()        const { return _physicObject->gravityEnabled(); }
    glm::vec3     linearLockAxisFactor()  const { return _physicObject->linearLockAxisFactor(); }
    glm::vec3     angularLockAxisFactor() const { return _physicObject->angularLockAxisFactor(); }
    glm::vec3     velocity()              const { return _physicObject->velocity(); }
    glm::vec3     angularVelocity()       const { return _physicObject->angularVelocity(); }
private:
    void update(float deltaTime) override
    {
        transform()->setPosition(_physicObject->position());
        transform()->setRotation(_physicObject->orientation());
    }
};

}

#endif //ENGINE_RIGIDBODY_H