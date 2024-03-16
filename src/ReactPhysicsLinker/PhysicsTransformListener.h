#ifndef REACTIMPL_TRANSFORM_LISTENER_H
#define REACTIMPL_TRANSFORM_LISTENER_H

#include <reactphysics3d/reactphysics3d.h>
#include <memory>

#include "ITransformListener.h"
#include "Transform.h"

namespace ReactPhysicsImpl
{

	class PhysicsTransformListener : public Engine::ITransformListener
	{
	private:
		reactphysics3d::Transform*					_physicTransform;
		std::shared_ptr<Engine::Transform>			_observable;
	public:
		PhysicsTransformListener(reactphysics3d::Transform* physicTransform,
			std::shared_ptr<Engine::Transform> observable) :
			_physicTransform(physicTransform), _observable(observable)
		{}

		void handleActivityChange(bool activeSelf) override;
		void handlePositionChange() override;
		void handleRotationChange() override;
		void handleScaleChange() override {}
	};

}

#endif //REACTIMPL_TRANSFORM_LISTENER_H