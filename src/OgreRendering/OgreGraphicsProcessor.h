#ifndef OGREIMPL_GRAPHICS_PROC_H
#define OGREIMPL_GRAPHICS_PROC_H

#include "GraphicsProcessor.h"
#include "InputProcessor.h"
#include "OgreApp.h"

namespace OgreImpl
{

	class OgreGraphicsProcessor : public Engine::IGraphicsProcessor, public Engine::IInputProcessor
	{
	private:
		std::shared_ptr<OgreApp> _app;
	public:
		void initializeGraphics();

		void onGraphicSceneStarted(std::vector<std::shared_ptr<Engine::GameObject>>& sceneObjects) override;
		void updateGraphics(float deltaTime) override;
		float deltaTime() { return 0; }

		void initializeInput() {}
		bool hasToRun() override;
		void onInputSceneStarted(std::vector<std::shared_ptr<Engine::GameObject>>& sceneObjects) override {}
	};

}

#endif //OGREIMPL_GRAPHICS_PROC_H