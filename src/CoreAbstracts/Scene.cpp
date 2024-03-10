#include "Scene.h"

using namespace Engine;


void Scene::start()
{
    _graphicsProcessor->onGraphicSceneStarted(_sceneObjects);
    _physicsProcessor->onPhysicSceneStarted(_sceneObjects);
    _inputProcessor->onInputSceneStarted(_sceneObjects);

    for (std::shared_ptr<Engine::GameObject> object : _sceneObjects)
    {
        object->start();
    }
}

void Scene::updateModel(float deltaTime)
{
    for (std::shared_ptr<Engine::GameObject> object : _sceneObjects)
    {
        object->update(deltaTime);
    }
}

void Scene::updateGraphics(float deltaTime)
{
    _graphicsProcessor->updateGraphics(deltaTime);
}

void Scene::updatePhysics(float deltaTime)
{
    _physicsProcessor->updatePhysics(deltaTime);
}

void Scene::instantiate(std::shared_ptr<GameObject> newObject)
{
    _sceneObjects.push_back(newObject);
}
