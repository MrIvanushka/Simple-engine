#ifndef ENGINE_MESHRENDERER_H
#define ENGINE_MESHRENDERER_H

#include <string>

#include "../Component.h"

namespace Engine
{

class IMeshRenderer
{
public:
	virtual ~IMeshRenderer() = default;

	virtual void enable() = 0;

	virtual void disable() = 0;
};

# define SerializeField /**/

class MeshRenderer : public Component
{
private SerializeField:
	std::string _meshPath = "";

	std::shared_ptr<IMeshRenderer> _implementation = nullptr;
public:
	MeshRenderer(std::shared_ptr<GameObject> obj, std::shared_ptr<Input> input) : Component(obj, input) { }

	void initialize(std::string meshPath) { if(_meshPath == "") _meshPath = meshPath; }
	
	void initialize(std::shared_ptr<IMeshRenderer> implementation) { _implementation = implementation; }

	void onEnable() override
	{
		_implementation->enable();
	}

	void onDisable() override
	{
		_implementation->disable();
	}

	std::string meshPath() const { return _meshPath; }
};

}

#endif //OGREIMPL_MESHRENDERER_H