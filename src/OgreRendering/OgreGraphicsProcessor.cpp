#include "OgreGraphicsProcessor.h"


using namespace OgreImpl;
using namespace Engine;

void OgreGraphicsProcessor::initializeGraphics()
{
    _app->initApp();
    _app->getRoot()->startRendering();//??????
    _app->closeApp();
}

void onGraphicSceneStarted(std::vector<std::shared_ptr<Engine::GameObject>>& sceneObjects)
{

}