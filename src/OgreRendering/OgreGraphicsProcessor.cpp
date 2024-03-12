#include "OgreGraphicsProcessor.h"

using namespace OgreImpl;
using namespace Engine;

void OgreGraphicsProcessor::initializeGraphics()
{
    _app = std::make_shared<OgreApp>("New application");
    _app->initApp();
}

void OgreGraphicsProcessor::onGraphicSceneStarted(std::vector<std::shared_ptr<Engine::GameObject>>& sceneObjects)
{
    _app->generateObjects(sceneObjects);
}

bool OgreGraphicsProcessor::hasToRun()
{
    if (_app->hasToRun())
        return true;

    _app->closeApp();
    return false;
}

void OgreGraphicsProcessor::updateGraphics(float deltaTime)
{
    _app->getRoot()->renderOneFrame();
}