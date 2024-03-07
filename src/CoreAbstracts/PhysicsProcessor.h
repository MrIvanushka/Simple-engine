#ifndef ENGINE_PHYSICS_PROC_H
#define ENGINE_PHYSICS_PROC_H

#include <vector>
#include <memory>

#include "GameObject.h"

namespace Engine
{

class IPhysicsProcessor
{
public:
	virtual ~IPhysicsProcessor() = default;

	virtual void initialize() = 0;
	virtual void onSceneStarted(std::vector<std::shared_ptr<GameObject>>& sceneObjects) = 0;
	virtual void update(float deltaTime) = 0;

};

}

#endif //ENGINE_PHYSICS_PROC_H
