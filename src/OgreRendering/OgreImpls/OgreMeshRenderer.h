#ifndef OGREIMPL_MESHRENDERER_H
#define OGREIMPL_MESHRENDERER_H

#include <string>

#include <Ogre.h>

#include "Components/MeshRenderer.h"

namespace OgreImpl
{

class OgreMeshRenderer : public Engine::IMeshRenderer
{
private:
	Ogre::Entity* _sceneObject = nullptr;
public:

	OgreMeshRenderer(Ogre::Entity* sceneObject) : _sceneObject(sceneObject)
	{}
	
	void enable() override
	{
		_sceneObject->setVisible(true);
	}

	void disable() override
	{
		_sceneObject->setVisible(false);
	}
};

}

#endif //OGREIMPL_MESHRENDERER_H