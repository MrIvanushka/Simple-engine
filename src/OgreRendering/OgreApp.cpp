#include "OgreApp.h"

#include "OgreTransformImpl.h"
#include "Components/MeshRenderer.h"
#include "Components/Camera.h"
#include "Components/Light.h"

using namespace OgreImpl;
using namespace Engine;

bool OgreApp::keyPressed(const OgreBites::KeyboardEvent& evt)
{
    if (evt.keysym.sym == OgreBites::SDLK_ESCAPE)
    {
        //getRoot()->queueEndRendering();
        _hasToRun = false;
    }
    return true;
}

void OgreApp::setup(void)
{
    OgreBites::ApplicationContext::setup();

    addInputListener(this);

    Ogre::Root* root = getRoot();
    _sceneManager = root->createSceneManager();

    Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(_sceneManager);
}

void OgreApp::clear()
{

}

void OgreApp::generateObjects(std::vector<std::shared_ptr<GameObject>>& sceneObjects)
{
    for (auto sceneObject : sceneObjects)
    {
        auto transform = std::dynamic_pointer_cast<OgreTransformImpl>(sceneObject->transform());

        auto node = _sceneManager->getRootSceneNode()->createChildSceneNode();

        if (transform != nullptr)
            transform->linkGraphics(node);
        else
            continue;

        auto renderer = sceneObject->getComponent<MeshRenderer>();

        if (renderer != nullptr)
        {
            auto entity = _sceneManager->createEntity(renderer->meshPath());
            node->attachObject(entity);
        }

        auto camera = sceneObject->getComponent<Camera>();

        if (camera != nullptr)
        {
            auto sceneCam = _sceneManager->createCamera("Camera");
            camera->initializeSceneObject(sceneCam);
            node->attachObject(sceneCam);
            getRenderWindow()->addViewport(sceneCam);
        }

        auto light = sceneObject->getComponent<Light>();

        if (light != nullptr)
        {
            auto sceneLight = _sceneManager->createLight("Light", light->type());
            light->initializeSceneObject(sceneLight);
            node->attachObject(sceneLight);
        }
    }
}