#ifndef ENGINE_TRANSFORM_LISTENER_H
#define ENGINE_TRANSFORM_LISTENER_H

namespace Engine
{

class ITransformListener
{
public:
	virtual ~ITransformListener() = default;

	virtual void handleActivityChange(bool activeSelf) = 0;
	virtual void handlePositionChange() = 0;
	virtual void handleRotationChange() = 0;
	virtual void handleScaleChange() = 0;
};

}

#endif //ENGINE_TRANSFORM_LISTENER_H
