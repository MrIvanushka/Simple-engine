#ifndef OGREIMPL_APP_H
#define OGREIMPL_APP_H

#include <Ogre.h>
#include <OgreApplicationContext.h>
#include <OgreRTShaderSystem.h>
#include <OgreInput.h>

#include <vector>

#include "GameObject.h"

namespace OgreImpl
{

class OgreApp : public OgreBites::ApplicationContext, public OgreBites::InputListener
{
    Ogre::SceneManager* _sceneManager;
public:
    OgreApp(Ogre::String name) : OgreBites::ApplicationContext(name)
    {}

    void setup(void);

    bool keyPressed(const OgreBites::KeyboardEvent& evt);

    void clear();

    void generateObjects(std::vector<std::shared_ptr<Engine::GameObject>>& sceneObjects);
};

}

#endif //OGREIMPL_APP_H