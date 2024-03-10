#ifndef ENGINE_INPUT_PROC_H
#define ENGINE_INPUT_PROC_H

#include <vector>
#include <memory>

#include "GameObject.h"

namespace Engine
{

class IInputProcessor
{
public:
	virtual ~IInputProcessor() = default;

	virtual void initializeInput() = 0;
	virtual void onInputSceneStarted(std::vector<std::shared_ptr<GameObject>>& sceneObjects) = 0;
	virtual float deltaTime() = 0;
	virtual bool hasToRun() = 0;
};

}

#endif //ENGINE_INPUT_PROC_H