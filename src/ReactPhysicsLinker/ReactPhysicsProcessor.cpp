#include "ReactPhysicsProcessor.h"

using namespace ReactPhysicsImpl;
using namespace reactphysics3d;

void ReactPhysicsProcessor::initializePhysics()
{
	_world = _physicsCommon.createPhysicsWorld();

}

void ReactPhysicsProcessor::onPhysicSceneStarted(std::vector<std::shared_ptr<Engine::GameObject>>& sceneObjects)
{

}

void ReactPhysicsProcessor::updatePhysics(float deltaTime)
{
	_world->update(deltaTime);
}