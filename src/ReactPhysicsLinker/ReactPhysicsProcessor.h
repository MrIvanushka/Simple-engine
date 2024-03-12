#ifndef REACTIMPL_PHYSICS_PROC_H
#define REACTIMPL_PHYSICS_PROC_H

#include "PhysicsProcessor.h"

namespace ReactPhysicsImpl
{

	class ReactPhysicsProcessor : public Engine::IPhysicsProcessor
	{
	private:
		
	public:
		void initializePhysics() override;

		void onPhysicSceneStarted(std::vector<std::shared_ptr<Engine::GameObject>>& sceneObjects) override;

		void updatePhysics(float deltaTime) override;
	};

}

#endif //REACTIMPL_PHYSICS_PROC_H