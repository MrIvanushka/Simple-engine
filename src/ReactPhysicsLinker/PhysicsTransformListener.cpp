#include "PhysicsTransformListener.h"

using namespace ReactPhysicsImpl;

reactphysics3d::Vector3 castTo(const glm::vec3& vec)
{
	return reactphysics3d::Vector3(vec.x, vec.y, vec.z);
}

reactphysics3d::Quaternion castTo(const glm::quat & quat)
{
	return reactphysics3d::Quaternion(quat.x, quat.y, quat.z, quat.w);
}

void PhysicsTransformListener::handleActivityChange(bool activeSelf)
{

}

void PhysicsTransformListener::handlePositionChange()
{
	_physicTransform->setPosition(castTo(_observable->position()));
}

void PhysicsTransformListener::handleRotationChange()
{
	_physicTransform->setOrientation(castTo(_observable->rotation()));
}