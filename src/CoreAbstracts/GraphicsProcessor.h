#ifndef ENGINE_GRAPHICS_PROC_H
#define ENGINE_GRAPHICS_PROC_H

#include <vector>
#include <memory>

#include "GameObject.h"

namespace Engine
{

class IGraphicsProcessor
{
public:
	virtual ~IGraphicsProcessor() = default;

	virtual void initializeGraphics() = 0;
	virtual void onGraphicSceneStarted(std::vector<std::shared_ptr<GameObject>>& sceneObjects) = 0;
	virtual void updateGraphics(float deltaTime) = 0;

};

}

#endif //ENGINE_GRAPHICS_PROC_H