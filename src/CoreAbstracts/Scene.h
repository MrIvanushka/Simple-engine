#ifndef ENGINE_SCENE_H
#define ENGINE_SCENE_H

#include <vector>
#include <memory>

#include "GameObject.h"
#include "GraphicsProcessor.h"
#include "InputProcessor.h"
#include "PhysicsProcessor.h"

namespace Engine
{

class Scene
{
private:
    std::shared_ptr<IPhysicsProcessor> _physicsProcessor;
    std::shared_ptr<IGraphicsProcessor> _graphicsProcessor;
    std::shared_ptr<IInputProcessor> _inputProcessor;

    std::vector<std::shared_ptr<GameObject>> _sceneObjects;
public:
    Scene(std::shared_ptr<IPhysicsProcessor> physicsProcessor,
        std::shared_ptr<IGraphicsProcessor> graphicsProcessor,
        std::shared_ptr<IInputProcessor> inputProcessor) :
        _physicsProcessor(physicsProcessor), _graphicsProcessor(graphicsProcessor),
        _inputProcessor(inputProcessor)
    {  }

    virtual ~Scene() = default;

    void start();
    void updateModel(float deltaTime);
    void updateGraphics(float deltaTime);
    void updatePhysics(float deltaTime);

protected:
    void instantiate(std::shared_ptr<GameObject> newObject);

};

}

#endif //ENGINE_SCENE_H
