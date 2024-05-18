#ifndef ENGINE_CAMERA_H
#define ENGINE_CAMERA_H

#include "../Component.h"

namespace Engine
{

class ICamera
{
public:
	virtual ~ICamera() = default;

	virtual void setFarClipDistance(float value) = 0;
	virtual void setNearClipDistance(float value) = 0;
	virtual void setFov(float value) = 0;

	virtual float farClipDistance() const = 0;
	virtual float nearClipDistance() const = 0;
	virtual float fov() const = 0;
};

class Camera : public Component
{
private:
	std::shared_ptr<ICamera> _sceneObject = nullptr;

	float _farClipDistance = 10000;
	float _nearClipDistance = 5;
	float _fov = 60;
public:
	Camera(std::shared_ptr<GameObject> obj, std::shared_ptr<Input> input) : Component(obj, input) { }

	void initialize(std::shared_ptr<ICamera> sceneObject)
	{
		_sceneObject = sceneObject;

		_sceneObject->setFarClipDistance(_farClipDistance);
		_sceneObject->setNearClipDistance(_nearClipDistance);
		_sceneObject->setFov(_fov);
	}

	void setFarClipDistance(float value) { if (_sceneObject != nullptr) _sceneObject->setFarClipDistance(value); else _farClipDistance = value; }
	void setNearClipDistance(float value) { if (_sceneObject != nullptr) _sceneObject->setNearClipDistance(value); else _nearClipDistance = value; }
	void setFov(float value) { if (_sceneObject != nullptr) _sceneObject->setFov(value); else _fov = value; }
		
	float farClipDistance() const { return _sceneObject->farClipDistance(); }
	float nearClipDistance() const { return _sceneObject->nearClipDistance(); }
	float fov() const { return _sceneObject->fov(); }
};

}

#endif //ENGINE_CAMERA_H