#include "OgreGraphicsProcessor.h"


using namespace OgreImpl;
using namespace Engine;

void OgreGraphicsProcessor::initializeGraphics()
{
    _app->initApp();
    _app->getRoot()->startRendering();//??????
    _app->closeApp();
}

void OgreGraphicsProcessor::onGraphicSceneStarted(std::vector<std::shared_ptr<Engine::GameObject>>& sceneObjects)
{
    _app->generateObjects(sceneObjects);
}