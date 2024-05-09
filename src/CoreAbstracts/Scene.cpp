#include "Scene.h"

using namespace Engine;


void Scene::start()
{
    for (auto object : _sceneObjects)
    {
        object->start();
    }
}

void Scene::update(float deltaTime)
{
    for (auto object : _sceneObjects)
    {
        object->update(deltaTime);
    }
}

std::shared_ptr<GameObject> Scene::instantiate(std::shared_ptr<Transform> transform)
{
    auto entity = std::make_shared<Entity>(transform, _input);
    _sceneObjects.push_back(entity);
    _sceneObjectsExp.push_back(entity);
    return entity;
}
