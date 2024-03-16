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
		std::shared_ptr<reactphysics3d::Transform>	_physicTransform;
		std::shared_ptr<Engine::Transform>			_observable;
	public:
		PhysicsTransformListener(std::shared_ptr<Engine::Transform> observable);

		void handleActivityChange(bool activeSelf) override;
		void handlePositionChange() override;
		void handleRotationChange() override;
		void handleScaleChange() override {}

		std::shared_ptr<reactphysics3d::Transform>	physicTransform() { return _physicTransform; }
	};

}

#endif //REACTIMPL_TRANSFORM_LISTENER_H