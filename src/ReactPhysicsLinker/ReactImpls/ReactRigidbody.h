#ifndef REACTIMPL_RIGIDBODY_H
#define REACTIMPL_RIGIDBODY_H


#include <reactphysics3d/reactphysics3d.h>
#include <glm/glm.hpp>

#include "Components/Rigidbody.h"

namespace ReactPhysicsImpl
{

class ReactRigidbody : public Engine::IRigidbody
{
private:
    reactphysics3d::RigidBody* _physicObject = nullptr;

public:
    ReactRigidbody(reactphysics3d::RigidBody* physicObject) : _physicObject(physicObject) {}

    void setType(Engine::RigidbodyType type) override;
    void setMass(float mass) override { _physicObject->setMass(mass); }

    void setLinearLockAxisFactor(glm::vec3 axisFactor) override;
    void setAngularLockAxisFactor(glm::vec3 axisFactor) override;

    void switchGravity(bool enabled) override { _physicObject->enableGravity(enabled); }

    void setVelocity(glm::vec3 velocity) override;
    void setAngularVelocity(glm::vec3 angularVelocity) override;

    Engine::RigidbodyType       type()                  const override;
    float                       mass()                  const override { return _physicObject->getMass(); }
    bool                        gravityEnabled()        const override { return _physicObject->isGravityEnabled(); }
    glm::vec3                   linearLockAxisFactor()  const override;
    glm::vec3                   angularLockAxisFactor() const override;
    glm::vec3                   velocity()              const override;
    glm::vec3                   angularVelocity()       const override;
    glm::vec3                   position()              const override;
    glm::quat                   orientation()           const override;

};

}

#endif //REACTIMPL_RIGIDBODY_H