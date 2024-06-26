#ifndef ENGINE_GAME_H
#define ENGINE_GAME_H

#include "Scene.h"
#include "ISceneLoader.h"
#include <chrono>

#include "GraphicsProcessor.h"
#include "PhysicsProcessor.h"
#include "InputProcessor.h"

namespace Engine
{

class Game final : public ISceneLoader
{
private:
    std::shared_ptr<IPhysicsProcessor> _physicsProcessor;
    std::shared_ptr<IGraphicsProcessor> _graphicsProcessor;
    std::shared_ptr<IInputProcessor> _inputProcessor;

    std::vector<std::shared_ptr<Scene>> _scenes;
    unsigned _currentSceneIndex;

public:
    Game(std::shared_ptr<IPhysicsProcessor> physicsProcessor,
        std::shared_ptr<IGraphicsProcessor> graphicsProcessor,
        std::shared_ptr<IInputProcessor> inputProcessor,
        std::vector<std::shared_ptr<Scene>> scenes) :
        _physicsProcessor(physicsProcessor), _graphicsProcessor(graphicsProcessor),
        _inputProcessor(inputProcessor), _scenes(scenes), _currentSceneIndex(0)
    {
        _graphicsProcessor->initializeGraphics();
        _physicsProcessor->initializePhysics();
        _inputProcessor->initializeInput();
    }
    void loadScene(unsigned newSceneIndex) override;

    void run();

};

}

#endif //ENGINE_GAME_H
