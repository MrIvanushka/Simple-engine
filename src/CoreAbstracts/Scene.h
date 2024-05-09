#ifndef ENGINE_SCENE_H
#define ENGINE_SCENE_H

#include <vector>
#include <memory>

#include "GameObject.h"
#include "Input.h"

namespace Engine
{

class Scene
{
private:
    std::vector<std::shared_ptr<Entity>> _sceneObjects;
    std::vector<std::shared_ptr<GameObject>> _sceneObjectsExp;
    std::shared_ptr<Input>               _input;
public:
    Scene(std::shared_ptr<Input> input) : _input(input) {}

    virtual ~Scene() = default;

    void start();
    void update(float deltaTime);

    const std::vector<std::shared_ptr<GameObject>>& sceneObjects() { return _sceneObjectsExp; }

protected:
    std::shared_ptr<GameObject> instantiate(std::shared_ptr<Transform> transform);
};

}

#endif //ENGINE_SCENE_H
