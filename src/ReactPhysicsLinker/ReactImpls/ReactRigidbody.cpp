#include "ReactRigidbody.h"
#include <glm/gtx/quaternion.hpp>

using namespace ReactPhysicsImpl;

reactphysics3d::Vector3 castToVec(const glm::vec3& vec)
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

void ReactRigidbody::setLinearLockAxisFactor(glm::vec3 axisFactor)
{
	_physicObject->setLinearLockAxisFactor(castToVec(axisFactor));
}

void ReactRigidbody::setAngularLockAxisFactor(glm::vec3 axisFactor)
{
	_physicObject->setAngularLockAxisFactor(castToVec(axisFactor));
}

void ReactRigidbody::setVelocity(glm::vec3 velocity)
{
	_physicObject->setLinearVelocity(castToVec(velocity));
}

void ReactRigidbody::setAngularVelocity(glm::vec3 angularVelocity)
{
	_physicObject->setAngularVelocity(castToVec(angularVelocity));
}

glm::vec3 ReactRigidbody::linearLockAxisFactor()  const { return castFrom(_physicObject->getLinearLockAxisFactor()); }
glm::vec3 ReactRigidbody::angularLockAxisFactor() const { return castFrom(_physicObject->getAngularLockAxisFactor()); }
glm::vec3 ReactRigidbody::velocity()              const { return castFrom(_physicObject->getLinearVelocity()); }
glm::vec3 ReactRigidbody::angularVelocity()       const { return castFrom(_physicObject->getAngularVelocity()); }
glm::vec3 ReactRigidbody::position()			  const { return castFrom(_physicObject->getTransform().getPosition()); }
glm::quat ReactRigidbody::orientation()			  const { return castFrom(_physicObject->getTransform().getOrientation()); }

void ReactRigidbody::setType(Engine::RigidbodyType type)
{
	switch (type)
	{
	case Engine::RB_KINEMATIC:
		_physicObject->setType(reactphysics3d::BodyType::KINEMATIC);
		break;
	case Engine::RB_DYNAMIC:
		_physicObject->setType(reactphysics3d::BodyType::DYNAMIC);
		break;
	case Engine::RB_STATIC:
		_physicObject->setType(reactphysics3d::BodyType::STATIC);
		break;
	default:
		break;
	}
}

Engine::RigidbodyType ReactRigidbody::type() const
{
	switch (_physicObject->getType())
	{
	case reactphysics3d::BodyType::KINEMATIC:
		return Engine::RB_KINEMATIC;
	case reactphysics3d::BodyType::DYNAMIC:
		return Engine::RB_DYNAMIC;
	case reactphysics3d::BodyType::STATIC:
		return Engine::RB_STATIC;
	}
	return Engine::RB_DYNAMIC;
}