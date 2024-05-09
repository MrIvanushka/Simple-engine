#ifndef OGREIMPL_LIGHT_H
#define OGREIMPL_LIGHT_H

#include <Ogre.h>

#include "Components/Light.h"

namespace OgreImpl
{

class OgreLight : public Engine::ILight
{
private:
	Engine::LightType _type = Engine::L_POINT;

	Ogre::Light* _sceneObject = nullptr;

	float _range = 10000000;
	float _intensity = 1;
	float _linearFactor = 0;
	float _quadricFactor = 0;
public:
	OgreLight(Ogre::Light* sceneObject) : _sceneObject(sceneObject)
	{}

	void enable() override
	{
		_sceneObject->setVisible(true);
	}

	void disable() override
	{
		_sceneObject->setVisible(false);
	}

	void setType(Engine::LightType type)
	{
		_type = type;

		switch (type)
		{
		case Engine::L_POINT:
			_sceneObject->setType(Ogre::Light::LT_POINT);
			break;
		case Engine::L_DIRECTIONAL:
			_sceneObject->setType(Ogre::Light::LT_DIRECTIONAL);
			break;
		case Engine::L_SPOT:
			_sceneObject->setType(Ogre::Light::LT_SPOTLIGHT);
			break;
		}
	}

	void setRange(float value) { _range = value; setAttenuation(); }
	void setIntensity(float value) { _intensity = value; setAttenuation(); }
	void setLinearAttenuationFactor(float value) { _linearFactor = value; setAttenuation(); }
	void setQuadricAttenuationFactor(float value) { _quadricFactor = value; setAttenuation(); }

	float range() const { return _sceneObject->getAttenuationRange(); }
	float intensity() const { return _sceneObject->getAttenuationConstant(); }
	float linearAttenuationFactor() const { return _sceneObject->getAttenuationLinear(); }
	float quadricAttenuationFactor() const { return _sceneObject->getAttenuationQuadric(); }

	Engine::LightType type() const { return _type; }

private:
	void setAttenuation() { _sceneObject->setAttenuation(_range, _intensity, _linearFactor, _quadricFactor); }
};

}

#endif //OGREIMPL_LIGHT_H