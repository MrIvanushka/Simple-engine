#ifndef OGREIMPL_LIGHT_H
#define OGREIMPL_LIGHT_H

#include <Ogre.h>

#include "Component.h"

namespace OgreImpl
{

class Light : public Engine::Component
{
private:
	Ogre::Light::LightTypes _type = Ogre::Light::LT_DIRECTIONAL;

	Ogre::Light* _sceneObject;

	float _range = 10000000;
	float _intensity = 1;
	float _linearFactor = 0;
	float _quadricFactor = 0;
public:
	Light(std::shared_ptr<Engine::GameObject> obj) : Component(obj) { }

	void initializeSceneObject(Ogre::Light* sceneObject)
	{
		_sceneObject = sceneObject;

		setAttenuation();
	}

	void onEnable() override
	{
		_sceneObject->setVisible(true);
	}

	void onDisable() override
	{
		_sceneObject->setVisible(false);
	}

	void setType(Ogre::Light::LightTypes type) { _type = type;  if (_sceneObject != nullptr) _sceneObject->setType(type); }

	void setRange(float value) { _range = value; if (_sceneObject != nullptr) setAttenuation(); }
	void setIntensity(float value) { _intensity = value; if (_sceneObject != nullptr) setAttenuation(); }
	void setLinearAttenuationFactor(float value) { _linearFactor = value; if (_sceneObject != nullptr) setAttenuation(); }
	void setQuadricAttenuationFactor(float value) { _quadricFactor = value; if (_sceneObject != nullptr) setAttenuation(); }

	float range() const { return _sceneObject->getAttenuationRange(); }
	float intensity() const { return _sceneObject->getAttenuationConstant(); }
	float linearAttenuationFactor() const { return _sceneObject->getAttenuationLinear(); }
	float quadricAttenuationFactor() const { return _sceneObject->getAttenuationQuadric(); }

	Ogre::Light::LightTypes type() const { return _type; }

private:
	void setAttenuation() { _sceneObject->setAttenuation(_range, _intensity, _linearFactor, _quadricFactor); }
};

}

#endif //OGREIMPL_LIGHT_H