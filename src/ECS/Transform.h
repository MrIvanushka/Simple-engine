#ifndef ENGINE_TRANSFORM_H
#define ENGINE_TRANSFORM_H

#define GLM_ENABLE_EXPERIMENTAL

#include <memory>
#include <set>

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

#include "ITransformListener.h"

namespace Engine
{
class Entity;

class Transform
{
private:
	std::set<std::shared_ptr<ITransformListener>> _listeners;

public:
	friend class GameObject;

	virtual ~Transform() = default;

	void addListener(std::shared_ptr<ITransformListener> listener);
	void removeListener(std::shared_ptr<ITransformListener> listener);

	void move(glm::vec3 delta);
	virtual void rotate(glm::quat delta);
	virtual void resize(glm::vec3 delta);

	virtual void setPosition(glm::vec3 newPos);
	virtual void setRotation(glm::quat newRot);
	virtual void setScale(glm::vec3 newScale);

	virtual void setLocalPosition(glm::vec3 newPos);
	virtual void setLocalRotation(glm::quat newRot);
	virtual void setLocalScale(glm::vec3 newScale);

	virtual void changeParent(std::shared_ptr<Transform> newParent) = 0;

	virtual glm::vec3 localPosition() const = 0;
	virtual glm::quat localRotation() const = 0;
	virtual glm::vec3 localScale() const = 0;

	virtual glm::vec3 position() const = 0;
	virtual glm::quat rotation() const = 0;
	virtual glm::vec3 scale() const = 0;
private:
	void handleActivityChange(bool value);

	virtual void onActivityChange(bool value) {}
	
	void invokePositionChange();
	void invokeRotationChange();
	void invokeScaleChange();

	virtual void _move(glm::vec3 delta) = 0;
	virtual void _rotate(glm::quat delta) = 0;
	virtual void _resize(glm::vec3 delta) = 0;

	virtual void _setPosition(glm::vec3 newPos) = 0;
	virtual void _setRotation(glm::quat newRot) = 0;
	virtual void _setScale(glm::vec3 newScale) = 0;

	virtual void _setLocalPosition(glm::vec3 newPos) = 0;
	virtual void _setLocalRotation(glm::quat newRot) = 0;
	virtual void _setLocalScale(glm::vec3 newScale) = 0;
};

}

#endif //ENGINE_TRANSFORM_H
