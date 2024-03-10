#include "Game.h"

using namespace Engine;

void Game::loadScene(unsigned newSceneIndex)
{
    _currentSceneIndex = newSceneIndex;
}

void Game::run()
{
    while (_inputProcessor->hasToRun())
    {
        update();
        render();
    }
}

void Game::update()
{
    _scenes[_currentSceneIndex]->updateModel(_inputProcessor->deltaTime());
}

void Game::render()
{
    _scenes[_currentSceneIndex]->updateGraphics(_inputProcessor->deltaTime());
}

