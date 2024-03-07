#include "Scene.h"

using namespace Engine;


void Scene::start()
{
    for (auto object : _sceneObjects)
    {
        object->start();
    }
    _graphicsProcessor->onSceneStarted(_sceneObjects);
    _physicsProcessor->onSceneStarted(_sceneObjects);
}

void Scene::updateModel(float deltaTime)
{
    for (auto object : _sceneObjects)
    {
        object->update(deltaTime);
    }
}

void Scene::updateGraphics(float deltaTime)
{
    _graphicsProcessor->update(deltaTime);
}

void Scene::updatePhysics(float deltaTime)
{
    _physicsProcessor->update(deltaTime);
}

void Scene::instantiate(std::shared_ptr<GameObject> newObject)
{
    _sceneObjects.push_back(newObject);
}
