#ifndef OGREIMPL_TRANSFORMIMPL_H
#define OGREIMPL_TRANSFORMIMPL_H

#include <Ogre.h>

#include "Transform.h"

namespace OgreImpl
{

class OgreTransformImpl final : public Engine::Transform
{
private:
	bool _linkGfx = false;

	Ogre::SceneNode* _graphicsRef;

	glm::vec3 _localPos;
	glm::quat _localRot;
	glm::vec3 _localScale;
	std::shared_ptr<Transform> _parent;
public:
	OgreTransformImpl(glm::vec3 localPos, glm::quat localRot, glm::vec3 localScale, std::shared_ptr<Transform> parent) :
		_localPos(localPos), _localRot(localRot), _localScale(localScale), _parent(parent) {}

	void linkGraphics(Ogre::SceneNode* graphicsRef);

	void changeParent(std::shared_ptr<Transform> newParent) override;

	Ogre::SceneNode* graphics() { return _graphicsRef; }

	glm::vec3 localPosition() const override;
	glm::quat localRotation() const override;
	glm::vec3 localScale() const override;

	glm::vec3 position() const override;
	glm::quat rotation() const override;
	glm::vec3 scale() const override;
private:
	void onActivityChange(bool value) override;

	void _move(glm::vec3 delta) override;
	void _rotate(glm::quat delta) override;
	void _resize(glm::vec3 delta) override;

	void _setPosition(glm::vec3 newPos) override;
	void _setRotation(glm::quat newRot) override;
	void _setScale(glm::vec3 newScale) override;

	void _setLocalPosition(glm::vec3 newPos) override;
	void _setLocalRotation(glm::quat newRot) override;
	void _setLocalScale(glm::vec3 newScale) override;
};

}

#endif //OGREIMPL_APP_H