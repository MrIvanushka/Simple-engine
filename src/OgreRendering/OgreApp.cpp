#include "OgreApp.h"

#include "OgreTransformImpl.h"
#include "Components/MeshRenderer.h"
#include "Components/Camera.h"
#include "Components/DirectionalLight.h"
#include "Components/PointLight.h"
#include "Components/SpotLight.h"

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

        auto nodeRaw = _sceneManager->getRootSceneNode()->createChildSceneNode();
        auto node = std::make_shared<Ogre::SceneNode>(*nodeRaw);

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
            sceneCam->setNearClipDistance(5); // specific to this sample
            sceneCam->setAutoAspectRatio(true);
            node->attachObject(sceneCam);
            getRenderWindow()->addViewport(sceneCam);
        }

        auto directionalLight = sceneObject->getComponent<DirectionalLight>();

        if (directionalLight != nullptr)
        {
            auto sceneLight = _sceneManager->createLight("DirectionalLight", Ogre::Light::LT_DIRECTIONAL);
            node->attachObject(sceneLight);
        }

        auto pointLight = sceneObject->getComponent<PointLight>();

        if (pointLight != nullptr)
        {
            auto sceneLight = _sceneManager->createLight("PointLight", Ogre::Light::LT_POINT);
            node->attachObject(sceneLight);
        }

        auto spotLight = sceneObject->getComponent<SpotLight>();

        if (spotLight != nullptr)
        {
            auto sceneLight = _sceneManager->createLight("SpotLight", Ogre::Light::LT_SPOTLIGHT);
            node->attachObject(sceneLight);
        }
    }
}