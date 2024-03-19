#include "Scene.h"

using namespace Engine;


void Scene::start()
{
    for (std::shared_ptr<Engine::GameObject> object : _sceneObjects)
    {
        object->start();
    }
}

void Scene::update(float deltaTime)
{
    for (std::shared_ptr<Engine::GameObject> object : _sceneObjects)
    {
        object->update(deltaTime);
    }
}

void Scene::instantiate(std::shared_ptr<GameObject> newObject)
{
    _sceneObjects.push_back(newObject);
}
