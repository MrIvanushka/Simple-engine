#include "OgreApp.h"

#include "OgreTransformImpl.h"
#include "Components/MeshRenderer.h"
#include "Components/Camera.h"
#include "Components/Light.h"

using namespace OgreImpl;
using namespace Engine;

bool OgreApp::keyPressed(const OgreBites::KeyboardEvent& evt)
{
    _pressedKeys.insert(static_cast<Engine::Key>(evt.keysym.sym));
    _holdingKeys.insert(static_cast<Engine::Key>(evt.keysym.sym));

    if (evt.keysym.sym == OgreBites::SDLK_ESCAPE)
    {
        //getRoot()->queueEndRendering();
        _hasToRun = false;
    }
    return true;
}

bool OgreApp::keyReleased(const OgreBites::KeyboardEvent& evt)
{
    _releasedKeys.insert(static_cast<Engine::Key>(evt.keysym.sym));
    _holdingKeys.erase(static_cast<Engine::Key>(evt.keysym.sym));

    return true;
}

bool OgreApp::mouseMoved(const OgreBites::MouseMotionEvent& evt)
{
    _mousePos = glm::vec2(evt.x, evt.y);
    return true;
}


bool OgreApp::mousePressed(const OgreBites::MouseButtonEvent& evt)
{
    MouseButton pressedButton;

    switch (evt.button)
    {
    case OgreBites::BUTTON_LEFT:
        pressedButton = MouseButton::LEFT;
        break;
    case OgreBites::BUTTON_RIGHT:
        pressedButton = MouseButton::RIGHT;
        break;
    case OgreBites::BUTTON_MIDDLE:
        pressedButton = MouseButton::MIDDLE;
        break;
    }

    _pressedButtons.insert(pressedButton);
    _holdingButtons.insert(pressedButton);

    return true;
}

bool OgreApp::mouseReleased(const OgreBites::MouseButtonEvent& evt)
{
    MouseButton pressedButton;

    switch (evt.button)
    {
    case OgreBites::BUTTON_LEFT:
        pressedButton = MouseButton::LEFT;
        break;
    case OgreBites::BUTTON_RIGHT:
        pressedButton = MouseButton::RIGHT;
        break;
    case OgreBites::BUTTON_MIDDLE:
        pressedButton = MouseButton::MIDDLE;
        break;
    }

    _releasedButtons.insert(pressedButton);
    _holdingButtons.erase(pressedButton);

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

void OgreApp::updateInputBuffers()
{
    _pressedKeys.clear();
    _pressedButtons.clear();
    _releasedKeys.clear();
    _releasedButtons.clear();
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
            throw std::exception();

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
            auto sceneLight = _sceneManager->createLight("Light");
            light->initializeSceneObject(sceneLight);
            node->attachObject(sceneLight);
        }
    }
}