#ifndef OGREIMPL_MESHRENDERER_H
#define OGREIMPL_MESHRENDERER_H

#include <string>

#include "Component.h"

namespace OgreImpl
{

class MeshRenderer : public Engine::Component
{
private:
	std::string _meshPath;

	Ogre::Entity* _sceneObject;
public:
	MeshRenderer(std::shared_ptr<Engine::GameObject> obj) : Component(obj) { }

	void initialize(std::string meshPath) { _meshPath = meshPath; }
	
	void onEnable() override
	{
		_sceneObject->setVisible(true);
	}

	void onDisable() override
	{
		_sceneObject->setVisible(false);
	}

	void initializeSceneObject(Ogre::Entity* sceneObject)
	{
		_sceneObject = sceneObject;
	}

	std::string meshPath() const { return _meshPath; }
};

}

#endif //OGREIMPL_MESHRENDERER_H