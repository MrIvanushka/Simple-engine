#include "OgreGraphicsProcessor.h"
#include "Game.h"

int main()
{
	std::shared_ptr<Engine::IGraphicsProcessor> pp = std::make_shared<OgreImpl::OgreGraphicsProcessor>();

	pp->initializeGraphics();

	return 0;
}