#ifndef REACTIMPL_PHYSICS_PROC_H
#define REACTIMPL_PHYSICS_PROC_H

#include <reactphysics3d/reactphysics3d.h>
#include <memory>

#include "PhysicsProcessor.h"
#include "PhysicsTransformListener.h"

namespace ReactPhysicsImpl
{

class ReactPhysicsProcessor : public Engine::IPhysicsProcessor
{
private:
	reactphysics3d::PhysicsCommon _physicsCommon;
	reactphysics3d::PhysicsWorld* _world;

	std::vector<std::shared_ptr<PhysicsTransformListener>> _transformListeners;
public:
	void initializePhysics() override;

	void onPhysicSceneStarted(std::vector<std::shared_ptr<Engine::GameObject>>& sceneObjects) override;

	void updatePhysics(float deltaTime) override;
};

}

#endif //REACTIMPL_PHYSICS_PROC_H