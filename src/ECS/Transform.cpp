#include "Transform.h"

using namespace Engine;

void Transform::addListener(std::shared_ptr<ITransformListener> listener)
{
	_listeners.insert(listener);
}

void Transform::removeListener(std::shared_ptr<ITransformListener> listener)
{
	_listeners.erase(listener);
}

void Transform::move(glm::vec3 delta)
{
	_move(delta);
	invokePositionChange();
}

void Transform::rotate(glm::quat delta)
{
	_rotate(delta);
	invokeRotationChange();
}

void Transform::resize(glm::vec3 delta)
{
	_resize(delta);
	invokeScaleChange();
}

void Transform::setPosition(glm::vec3 newPos)
{
	_setPosition(newPos);
	invokePositionChange();
}

void Transform::setRotation(glm::quat newRot)
{
	_setRotation(newRot);
	invokeRotationChange();
}

void Transform::setScale(glm::vec3 newScale)
{
	_setScale(newScale);
	invokeScaleChange();
}

void Transform::setLocalPosition(glm::vec3 newPos)
{
	_setLocalPosition(newPos);
	invokePositionChange();
}

void Transform::setLocalRotation(glm::quat newRot)
{
	_setLocalRotation(newRot);
	invokeRotationChange();
}

void Transform::setLocalScale(glm::vec3 newScale)
{
	_setLocalScale(newScale);
	invokeScaleChange();
}

void Transform::changeParent(std::shared_ptr<Transform> newParent)
{
	if (_parent != nullptr)
		_parent->_children.erase(shared_from_this());

	_changeParent(newParent);

	_parent = newParent;

	if (_parent != nullptr)
		_parent->_children.insert(shared_from_this());
}

void Transform::handleActivityChange(bool value)
{
	for (auto& listener : _listeners)
	{
		listener->handleActivityChange(value);
	}
	onActivityChange(value);
}

void Transform::invokePositionChange()
{
	for (auto& listener : _listeners)
	{
		listener->handlePositionChange();
	}
}

void Transform::invokeRotationChange()
{
	for (auto& listener : _listeners)
	{
		listener->handleRotationChange();
	}
}

void Transform::invokeScaleChange()
{
	for (auto& listener : _listeners)
	{
		listener->handleScaleChange();
	}
}