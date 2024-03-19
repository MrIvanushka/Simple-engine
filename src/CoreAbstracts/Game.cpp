#include "Game.h"

using namespace Engine;

void Game::loadScene(unsigned newSceneIndex)
{
    _currentSceneIndex = newSceneIndex;

    auto sceneObjects = _scenes[_currentSceneIndex]->sceneObjects();

    _graphicsProcessor->onGraphicSceneStarted(sceneObjects);
    _physicsProcessor->onPhysicSceneStarted(sceneObjects);
    _inputProcessor->onInputSceneStarted(sceneObjects);
    _scenes[_currentSceneIndex]->start();
}
#include <iostream>
void Game::run()
{
    loadScene(0);

    std::chrono::high_resolution_clock clock;
    float timeSinceLastPhysicsUpdate = 0;
    const float PHYSICS_UPDATE_RATE = 1 / 60;

    _graphicsProcessor->updateGraphics(PHYSICS_UPDATE_RATE);

    std::this_thread::sleep_for(std::chrono::seconds(1)); //подорожник для DirectX

    auto previousFrameTime = clock.now();

    while (_inputProcessor->hasToRun())
    {
        auto currentFrameTime = clock.now();
        auto deltaTimeRaw = std::chrono::duration_cast<std::chrono::microseconds>(currentFrameTime - previousFrameTime).count();
        float deltaTime = deltaTimeRaw / 1000000.;

        std::cout << "dt " << deltaTime << std::endl;

        timeSinceLastPhysicsUpdate += deltaTime;

        if (timeSinceLastPhysicsUpdate > PHYSICS_UPDATE_RATE)
        {
            _physicsProcessor->updatePhysics(timeSinceLastPhysicsUpdate);
            timeSinceLastPhysicsUpdate = 0;
        }

        _scenes[_currentSceneIndex]->update(deltaTime);
        _graphicsProcessor->updateGraphics(deltaTime);

        previousFrameTime = currentFrameTime;
    }
}

