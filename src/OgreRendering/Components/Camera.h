#ifndef OGREIMPL_CAMERA_H
#define OGREIMPL_CAMERA_H

#include <Ogre.h>

#include "Component.h"

namespace OgreImpl
{

class Camera : public Engine::Component
{
private:
	std::shared_ptr<Ogre::Camera> _sceneObject;

	float _farClipDistance = 100;
	float _nearClipDistance = 0;
	float _fov = 60;
public:
	void initializeSceneObject(std::shared_ptr<Ogre::Camera> sceneObject)
	{
		_sceneObject = sceneObject;

		_sceneObject->setFarClipDistance(_farClipDistance);
		_sceneObject->setNearClipDistance(_nearClipDistance);
		_sceneObject->setFOVy(Ogre::Degree(_fov));
	}

	void setFarClipDistance(float value) { if (_sceneObject != nullptr) _sceneObject->setFarClipDistance(value); else _farClipDistance = value; }
	void setNearClipDistance(float value) { if (_sceneObject != nullptr) _sceneObject->setNearClipDistance(value); else _nearClipDistance = value; }
	void setFov(float value) { if (_sceneObject != nullptr) _sceneObject->setFOVy(Ogre::Degree(value)); else _fov = value; }
		
	float farClipDistance() const { return _sceneObject->getFarClipDistance(); }
	float nearClipDistance() const { return _sceneObject->getNearClipDistance(); }
	float fov() const { return _sceneObject->getFOVy().valueDegrees(); }
};

}

#endif //OGREIMPL_CAMERA_H