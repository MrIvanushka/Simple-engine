#ifndef ENGINE_LIGHT_H
#define ENGINE_LIGHT_H

#include "../Component.h"

namespace Engine
{

enum LightType
{
	L_DIRECTIONAL,
	L_POINT,
	L_SPOT
};

class ILight
{
public:
	virtual ~ILight() = default;

	virtual void enable() = 0;
	virtual void disable() = 0;

	virtual void setType(LightType type) = 0;
	virtual void setRange(float value) = 0;
	virtual void setIntensity(float value) = 0;
	virtual void setLinearAttenuationFactor(float value) = 0;
	virtual void setQuadricAttenuationFactor(float value) = 0;

	virtual float range() const = 0;
	virtual float intensity() const = 0;
	virtual float linearAttenuationFactor() const = 0;
	virtual float quadricAttenuationFactor() const = 0;
	virtual LightType type() const = 0;
};

class Light : public Component
{
private:
	LightType _type = L_DIRECTIONAL;

	std::shared_ptr<ILight> _implementation = nullptr;

	float _range = 10000000;
	float _intensity = 1;
	float _linearFactor = 0;
	float _quadricFactor = 0;
public:
	Light(std::shared_ptr<GameObject> obj, std::shared_ptr<Input> input) : Component(obj, input) { }

	void initialize(std::shared_ptr<ILight> implementation)
	{
		_implementation = implementation;

		_implementation->setType(_type);
		_implementation->setRange(_range);
		_implementation->setIntensity(_intensity);
		_implementation->setLinearAttenuationFactor(_linearFactor);
		_implementation->setQuadricAttenuationFactor(_quadricFactor);
	}

	void onEnable() override
	{
		_implementation->enable();
	}

	void onDisable() override
	{
		_implementation->disable();
	}

	void setType(LightType type) { _type = type;  if (_implementation != nullptr) _implementation->setType(type); }

	void setRange(float value) { _range = value; if (_implementation != nullptr) _implementation->setRange(value); }
	void setIntensity(float value) { _intensity = value; if (_implementation != nullptr) _implementation->setIntensity(value); }
	void setLinearAttenuationFactor(float value) { _linearFactor = value; if (_implementation != nullptr) _implementation->setLinearAttenuationFactor(value); }
	void setQuadricAttenuationFactor(float value) { _quadricFactor = value; if (_implementation != nullptr) _implementation->setQuadricAttenuationFactor(value); }

	float range() const { return _implementation->range(); }
	float intensity() const { return _implementation->intensity(); }
	float linearAttenuationFactor() const { return _implementation->linearAttenuationFactor(); }
	float quadricAttenuationFactor() const { return _implementation->quadricAttenuationFactor(); }

	LightType type() const { return _implementation->type(); }
};

}

#endif //ENGINE_LIGHT_H