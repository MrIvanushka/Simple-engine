#ifndef OGREIMPL_CAMERA_H
#define OGREIMPL_CAMERA_H

#include <Ogre.h>

#include "Component.h"

namespace OgreImpl
{

class Camera : public Engine::Component
{
private:
	Ogre::Camera* _sceneObject;

	float _farClipDistance = 10000;
	float _nearClipDistance = 5;
	float _fov = 60;
public:
	Camera(std::shared_ptr<Engine::GameObject> obj) : Component(obj) { }

	void initializeSceneObject(Ogre::Camera* sceneObject)
	{
		_sceneObject = sceneObject;

		_sceneObject->setFarClipDistance(_farClipDistance);
		_sceneObject->setNearClipDistance(_nearClipDistance);
		_sceneObject->setAutoAspectRatio(true);
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