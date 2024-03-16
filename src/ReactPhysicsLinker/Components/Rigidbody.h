#ifndef REACTIMPL_RIGIDBODY_H
#define REACTIMPL_RIGIDBODY_H


#include <reactphysics3d/reactphysics3d.h>
#include <glm/glm.hpp>

#include "Component.h"

namespace ReactPhysicsImpl
{

class Rigidbody : public Engine::Component
{
private:
    reactphysics3d::RigidBody* _physicObject;

    reactphysics3d::BodyType _type;

    float _mass;
    bool _useGravity;

    reactphysics3d::Vector3 _linearLockAxisFactor;
    reactphysics3d::Vector3 _angularLockAxisFactor;
public:
    Rigidbody(std::shared_ptr<Engine::GameObject> obj) : Component(obj) { }

    void initialize(reactphysics3d::RigidBody* physicObject)
    {
        _physicObject = physicObject;

        _physicObject->setType(_type);
    }

    void initializeType(reactphysics3d::BodyType type) { if (_physicObject == nullptr) _type = type; else _physicObject->setType(type); }
    void initializeMass(float mass) { if (_physicObject == nullptr) _mass = mass; else _physicObject->setMass(mass); }

    void setLinearLockAxisFactor(glm::vec3 axisFactor);
    void setAngularLockAxisFactor(glm::vec3 axisFactor);

    void switchGravity(bool enabled) { if (_physicObject == nullptr) _useGravity = enabled; else _physicObject->enableGravity(enabled); }

    void update(float deltaTime) override;

    void setVelocity(glm::vec3 velocity);
    void setAngularVelocity(glm::vec3 angularVelocity);

    reactphysics3d::BodyType    type()                  const { return _physicObject->getType(); }
    float                       mass()                  const { return _physicObject->getMass(); }
    bool                        gravityEnabled()        const { return _physicObject->isGravityEnabled(); }
    glm::vec3                   linearLockAxisFactor()  const;
    glm::vec3                   angularLockAxisFactor() const;
    glm::vec3                   velocity()              const;
    glm::vec3                   angularVelocity()       const;

};

}

#endif //REACTIMPL_RIGIDBODY_H