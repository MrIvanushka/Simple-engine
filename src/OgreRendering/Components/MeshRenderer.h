#ifndef OGREIMPL_MESHRENDERER_H
#define OGREIMPL_MESHRENDERER_H

#include <string>

#include "Component.h"

namespace OgreImpl
{

class MeshRenderer : public Engine::Component
{
private:
	std::string _meshPath;
public:
	void initialize(std::string meshPath) { _meshPath = meshPath; }
	
	std::string meshPath() const { return _meshPath; }
};

}

#endif //OGREIMPL_MESHRENDERER_H