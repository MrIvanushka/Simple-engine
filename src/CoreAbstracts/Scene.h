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
        std::vector<std::shared_ptr<GameObject>> _sceneObjects;
    public:
        Scene(std::shared_ptr<Input> input) {}

        virtual ~Scene() = default;

        void start();
        void update(float deltaTime);

        std::vector<std::shared_ptr<GameObject>> sceneObjects() { return _sceneObjects; }

protected:
    void instantiate(std::shared_ptr<GameObject> newObject);
};

}

#endif //ENGINE_SCENE_H
