#ifndef OGREIMPL_GRAPHICS_PROC_H
#define OGREIMPL_GRAPHICS_PROC_H

#include "GraphicsProcessor.h"

namespace OgreImpl
{

	class OgreSdlProcessor : public Engine::IGraphicsProcessor
	{
	public:
		void initialize();
		void onSceneStarted(std::vector<std::shared_ptr<Engine::GameObject>>& sceneObjects) override {}
		void update(float deltaTime) override {}
	};

}

#endif //OGREIMPL_GRAPHICS_PROC_H