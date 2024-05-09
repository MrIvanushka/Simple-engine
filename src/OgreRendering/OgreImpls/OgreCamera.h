#ifndef OGREIMPL_CAMERA_H
#define OGREIMPL_CAMERA_H

#include <Ogre.h>

#include "Components/Camera.h"

namespace OgreImpl
{

class OgreCamera : public Engine::ICamera
{
private:
	Ogre::Camera* _sceneObject = nullptr;
public:
	OgreCamera(Ogre::Camera* sceneObject) : _sceneObject(sceneObject)
	{}

	void setFarClipDistance(float value) override { _sceneObject->setFarClipDistance(value); }
	void setNearClipDistance(float value) override { _sceneObject->setNearClipDistance(value); }
	void setFov(float value) override { _sceneObject->setFOVy(Ogre::Degree(value)); }
		
	float farClipDistance() const override { return _sceneObject->getFarClipDistance(); }
	float nearClipDistance() const override { return _sceneObject->getNearClipDistance(); }
	float fov() const override { return _sceneObject->getFOVy().valueDegrees(); }
};

}

#endif //OGREIMPL_CAMERA_H