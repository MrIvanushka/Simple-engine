#ifndef ENGINE_LOADER_H
#define ENGINE_LOADER_H

#include "Scene.h"

namespace Engine
{

class ISceneLoader
{
public:
	~ISceneLoader() = default;

	virtual void loadScene(unsigned newSceneIndex) = 0;
};

}

#endif //ENGINE_LOADER_H
