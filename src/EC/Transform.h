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

class Transform : public std::enable_shared_from_this<Transform>
{
private:
	std::set<std::shared_ptr<ITransformListener>> _listeners;

	std::set<std::shared_ptr<Transform>> _children;
	std::shared_ptr<Transform> _parent;
public:
	friend class GameObject;

	virtual ~Transform() = default;

	void addListener(std::shared_ptr<ITransformListener> listener);
	void removeListener(std::shared_ptr<ITransformListener> listener);

	void move(glm::vec3 delta);
	void rotate(glm::quat delta);
	void resize(glm::vec3 delta);

	void setPosition(glm::vec3 newPos);
	void setRotation(glm::quat newRot);
	void setScale(glm::vec3 newScale);

	void setLocalPosition(glm::vec3 newPos);
	void setLocalRotation(glm::quat newRot);
	void setLocalScale(glm::vec3 newScale);

	void changeParent(std::shared_ptr<Transform> newParent);

	std::shared_ptr<Transform> parent() const { return _parent; }
	const std::set<std::shared_ptr<Transform>>& children() const { return _children; }

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

	virtual void _changeParent(std::shared_ptr<Transform> newParent) = 0;

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
