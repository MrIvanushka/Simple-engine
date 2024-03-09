#ifndef OGREIMPL_GRAPHICS_PROC_H
#define OGREIMPL_GRAPHICS_PROC_H

#include "GraphicsProcessor.h"
#include "InputProcessor.h"

namespace OgreImpl
{

	class OgreSdlProcessor : public Engine::IGraphicsProcessor, public Engine::IInputProcessor
	{
	public:
		void initializeGraphics();
		void onGraphicSceneStarted(std::vector<std::shared_ptr<Engine::GameObject>>& sceneObjects) override {}
		void updateGraphics(float deltaTime) override {}
		float deltaTime() { return 0; }

		void initializeInput() {}
		void onInputSceneStarted(std::vector<std::shared_ptr<Engine::GameObject>>& sceneObjects) override {}
	};

}

#endif //OGREIMPL_GRAPHICS_PROC_H