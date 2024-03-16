#include "ReactPhysicsProcessor.h"

#include "Components/Rigidbody.h"
#include "Components/BoxCollider.h"
#include "Components/SphereCollider.h"

using namespace ReactPhysicsImpl;
using namespace reactphysics3d;

void ReactPhysicsProcessor::initializePhysics()
{
}

void ReactPhysicsProcessor::onPhysicSceneStarted(std::vector<std::shared_ptr<Engine::GameObject>>& sceneObjects)
{
	if(_world != nullptr)
		_physicsCommon.destroyPhysicsWorld(_world);

	_world = _physicsCommon.createPhysicsWorld();
    _transformListeners.clear();

	for (auto sceneObject : sceneObjects)
	{
        auto newListener = std::make_shared<PhysicsTransformListener>(sceneObject->transform());
        _transformListeners.push_back(newListener);

        auto rigidbody = sceneObject->getComponent<Rigidbody>();

        if (rigidbody != nullptr)
        {
            auto rb = _world->createRigidBody(*newListener->physicTransform());
            rigidbody->initialize(rb);

            auto boxCollider = sceneObject->getComponent<BoxCollider>();

            if (boxCollider != nullptr)
            {
                auto shape = _physicsCommon.createBoxShape(reactphysics3d::Vector3(1.,1.,1.));
                auto collider = rb->addCollider(shape, *newListener->physicTransform());
                boxCollider->initialize(collider, shape);
            }

            auto sphereCollider = sceneObject->getComponent<SphereCollider>();

            if (sphereCollider != nullptr)
            {
                auto shape = _physicsCommon.createSphereShape(1.);
                auto collider = rb->addCollider(shape, *newListener->physicTransform());
                sphereCollider->initialize(collider, shape);
            }
        }
	}
}

void ReactPhysicsProcessor::updatePhysics(float deltaTime)
{
	_world->update(deltaTime);
}