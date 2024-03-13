#include "Rigidbody.h"
#include <glm/gtx/quaternion.hpp>

using namespace ReactPhysicsImpl;

reactphysics3d::Vector3 castTo(const glm::vec3& vec)
{
	return reactphysics3d::Vector3(vec.x, vec.y, vec.z);
}

glm::vec3 castFrom(const reactphysics3d::Vector3& vec)
{
	return glm::vec3(vec.x, vec.y, vec.z);
}

glm::quat castFrom(const reactphysics3d::Quaternion& quat)
{
	return glm::quat(quat.x, quat.y, quat.z, quat.w);
}

void ReactPhysicsImpl::Rigidbody::setLinearLockAxisFactor(glm::vec3 axisFactor)
{
	if (_physicObject == nullptr)
		_linearLockAxisFactor = castTo(axisFactor);
	else
		_physicObject->setLinearLockAxisFactor(castTo(axisFactor));
}

void ReactPhysicsImpl::Rigidbody::setAngularLockAxisFactor(glm::vec3 axisFactor)
{
	if (_physicObject == nullptr)
		_angularLockAxisFactor = castTo(axisFactor);
	else
		_physicObject->setAngularLockAxisFactor(castTo(axisFactor));
}

void ReactPhysicsImpl::Rigidbody::update(float deltaTime)
{
	_gameObject->transform()->setPosition(castFrom(_physicObject->getTransform().getPosition()));
	_gameObject->transform()->setRotation(castFrom(_physicObject->getTransform().getOrientation()));
}

void ReactPhysicsImpl::Rigidbody::setVelocity(glm::vec3 velocity)
{
	_physicObject->setLinearVelocity(castTo(velocity));
}

void ReactPhysicsImpl::Rigidbody::setAngularVelocity(glm::vec3 angularVelocity)
{
	_physicObject->setAngularVelocity(castTo(angularVelocity));
}

glm::vec3 ReactPhysicsImpl::Rigidbody::linearLockAxisFactor()  const { return castFrom(_physicObject->getLinearLockAxisFactor()); }
glm::vec3 ReactPhysicsImpl::Rigidbody::angularLockAxisFactor() const { return castFrom(_physicObject->getAngularLockAxisFactor()); }
glm::vec3 ReactPhysicsImpl::Rigidbody::velocity()              const { return castFrom(_physicObject->getLinearVelocity()); }
glm::vec3 ReactPhysicsImpl::Rigidbody::angularVelocity()       const { return castFrom(_physicObject->getAngularVelocity()); }