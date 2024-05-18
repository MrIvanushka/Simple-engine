#include "OgreTransformImpl.h"

using namespace Engine;
using namespace OgreImpl;

Ogre::Vector3 castTo(const glm::vec3& vec)
{
	return Ogre::Vector3(vec.x, vec.y, vec.z);
}

Ogre::Quaternion castTo(const glm::quat& quat)
{
	return Ogre::Quaternion(quat.w, quat.x, quat.y, quat.z);
}

glm::vec3 castFrom(const Ogre::Vector3& vec)
{
	return glm::vec3(vec.x, vec.y, vec.z);
}

glm::quat castFrom(const Ogre::Quaternion& quat)
{
	return glm::quat(quat.w, quat.x, quat.y, quat.z);
}

void OgreTransformImpl::onActivityChange(bool value)
{
	_graphicsRef->flipVisibility();
}

void OgreTransformImpl::linkGraphics(Ogre::SceneNode* graphicsRef)
{
	_graphicsRef = graphicsRef;

	changeParent(_parent);

	_graphicsRef->setPosition(castTo(_localPos));
	_graphicsRef->setOrientation(castTo(_localRot));
	_graphicsRef->setScale(castTo(_localScale));
}

void OgreTransformImpl::_changeParent(std::shared_ptr<Transform> newParent)
{
	if (newParent != nullptr)
	{
		_graphicsRef->getParent()->removeChild(_graphicsRef);

		auto parent = std::dynamic_pointer_cast<OgreTransformImpl>(newParent);

		if (parent != nullptr)
			parent->graphics()->addChild(_graphicsRef);
	}
	_graphicsRef->setInheritOrientation(true);
	_graphicsRef->setInheritScale(true);
}

glm::vec3 OgreTransformImpl::localPosition() const 
{
	return castFrom(_graphicsRef->getPosition());
}

glm::quat OgreTransformImpl::localRotation() const 
{
	return castFrom(_graphicsRef->getOrientation());
}

glm::vec3 OgreTransformImpl::localScale() const 
{
	return castFrom(_graphicsRef->getScale());
}

glm::vec3 OgreTransformImpl::position() const 
{
	return castFrom(_graphicsRef->_getDerivedPosition());
}

glm::quat OgreTransformImpl::rotation() const 
{
	return castFrom(_graphicsRef->_getDerivedOrientation());
}

glm::vec3 OgreTransformImpl::scale() const 
{
	return castFrom(_graphicsRef->_getDerivedScale());
}

void OgreTransformImpl::_move(glm::vec3 delta) 
{
	_graphicsRef->translate(castTo(delta));
}

void OgreTransformImpl::_rotate(glm::quat delta) 
{
	_graphicsRef->rotate(castTo(delta));
}

void OgreTransformImpl::_resize(glm::vec3 delta) 
{
	_graphicsRef->scale(castTo(delta));
}

void OgreTransformImpl::_setPosition(glm::vec3 newPos) 
{
	_graphicsRef->_setDerivedPosition(castTo(newPos));
}

void OgreTransformImpl::_setRotation(glm::quat newRot) 
{
	_graphicsRef->_setDerivedOrientation(castTo(newRot));
}

void OgreTransformImpl::_setScale(glm::vec3 newScale) 
{
	_graphicsRef->setScale(castTo(newScale));
}

void OgreTransformImpl::_setLocalPosition(glm::vec3 newPos) 
{
	_graphicsRef->setPosition(castTo(newPos));
}

void OgreTransformImpl::_setLocalRotation(glm::quat newRot) 
{
	_graphicsRef->setOrientation(castTo(newRot));
}

void OgreTransformImpl::_setLocalScale(glm::vec3 newScale) 
{
	_graphicsRef->setScale(castTo(newScale));
}