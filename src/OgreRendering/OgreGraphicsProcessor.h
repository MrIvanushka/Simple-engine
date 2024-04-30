#ifndef OGREIMPL_GRAPHICS_PROC_H
#define OGREIMPL_GRAPHICS_PROC_H

#include <glm/glm.hpp>
#include <set>
#include <algorithm>

#include "GraphicsProcessor.h"
#include "InputProcessor.h"
#include "OgreApp.h"
#include "Input.h"

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

		void initializeInput() override {}
		bool hasToRun() override;
		void onInputSceneStarted(std::vector<std::shared_ptr<Engine::GameObject>>& sceneObjects) override {}

		void updateInput(float deltaTime);

		bool keyPressed(Engine::Key key) const override { return _app->keyPressed(key); }
		bool keyHolding(Engine::Key key) const override { return _app->keyHolding(key); }
		bool keyReleased(Engine::Key key) const override { return _app->keyReleased(key); }
		bool mouseMoved(glm::vec2& newPos) const override { return _app->mouseMoved(newPos); }
		bool mouseButtonPressed(Engine::MouseButton button) const override { return _app->mouseButtonPressed(button); }
		bool mouseButtonHolding(Engine::MouseButton button) const override { return _app->mouseButtonHolding(button); }
		bool mouseButtonReleased(Engine::MouseButton button) const override { return _app->mouseButtonReleased(button); }
		glm::vec2 mousePosition() const override { return _app->mousePosition(); }
	};

}

#endif //OGREIMPL_GRAPHICS_PROC_H