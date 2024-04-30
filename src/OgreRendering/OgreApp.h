#ifndef OGREIMPL_APP_H
#define OGREIMPL_APP_H

#include <Ogre.h>
#include <OgreApplicationContext.h>
#include <OgreRTShaderSystem.h>
#include <OgreInput.h>

#include <vector>
#include <unordered_set>

#include "GameObject.h"

namespace OgreImpl
{

class OgreApp : public OgreBites::ApplicationContext, public OgreBites::InputListener
{
    Ogre::SceneManager* _sceneManager;
    bool _hasToRun = true;

    std::unordered_set<Engine::Key>			_pressedKeys;
    std::unordered_set<Engine::MouseButton>	_pressedButtons;
    std::unordered_set<Engine::Key>			_releasedKeys;
    std::unordered_set<Engine::MouseButton>	_releasedButtons;
    std::unordered_set<Engine::Key>			_holdingKeys;
    std::unordered_set<Engine::MouseButton>	_holdingButtons;
    glm::vec2                               _mousePos;
public:
    OgreApp(Ogre::String name) : OgreBites::ApplicationContext(name)
    {}

    void setup(void);

    bool keyPressed(const OgreBites::KeyboardEvent& evt) override;
    bool keyReleased(const OgreBites::KeyboardEvent& evt) override;
    bool mouseMoved(const OgreBites::MouseMotionEvent& evt) override;
    bool mousePressed(const OgreBites::MouseButtonEvent& evt) override;
    bool mouseReleased(const OgreBites::MouseButtonEvent& evt) override;

    void clear();
    void updateInputBuffers();

    bool hasToRun() const { return _hasToRun; }

    void generateObjects(std::vector<std::shared_ptr<Engine::GameObject>>& sceneObjects);

    bool keyPressed(Engine::Key key) const { return _pressedKeys.find(key) != _pressedKeys.end(); }
    bool keyHolding(Engine::Key key) const { return _holdingKeys.find(key) != _holdingKeys.end(); }
    bool keyReleased(Engine::Key key) const { return _releasedKeys.find(key) != _releasedKeys.end(); }
    bool mouseMoved(glm::vec2& newPos) const { newPos = _mousePos;  return true; }
    bool mouseButtonPressed(Engine::MouseButton button) const { return _pressedButtons.find(button) != _pressedButtons.end(); }
    bool mouseButtonHolding(Engine::MouseButton button) const { return _holdingButtons.find(button) != _holdingButtons.end(); }
    bool mouseButtonReleased(Engine::MouseButton button) const { return _releasedButtons.find(button) != _releasedButtons.end(); }
    glm::vec2 mousePosition() const { return _mousePos; }
};

}

#endif //OGREIMPL_APP_H