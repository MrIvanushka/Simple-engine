#include "ReactPhysicsProcessor.h"

#include "ReactImpls/ReactRigidbody.h"
#include "ReactImpls/ReactBoxShape.h"
#include "ReactImpls/ReactSphereShape.h"
#include "ReactImpls/ReactCollider.h"

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

        auto rigidbody = sceneObject->getComponent<Engine::Rigidbody>();

        if (rigidbody != nullptr)
        {
            auto rb = _world->createRigidBody(*newListener->physicTransform());
            rigidbody->initialize(std::make_shared<ReactRigidbody>(rb));

            auto boxCollider = sceneObject->getComponent<Engine::BoxCollider>();

            if (boxCollider != nullptr)
            {
                auto shape = _physicsCommon.createBoxShape(reactphysics3d::Vector3(boxCollider->halfExtents().x, boxCollider->halfExtents().y, boxCollider->halfExtents().z));
                auto collider = rb->addCollider(shape, Transform::identity());
                boxCollider->initialize(std::make_shared<ReactCollider>(collider), std::make_shared<ReactBoxShape>(shape));
            }

            auto sphereCollider = sceneObject->getComponent<Engine::SphereCollider>();

            if (sphereCollider != nullptr)
            {
                auto shape = _physicsCommon.createSphereShape(1.);
                auto collider = rb->addCollider(shape, Transform::identity());
                sphereCollider->initialize(std::make_shared<ReactCollider>(collider), std::make_shared<ReactSphereShape>(shape));
            }
        }
	}
}

void ReactPhysicsProcessor::updatePhysics(float deltaTime)
{
	_world->update(deltaTime);
}