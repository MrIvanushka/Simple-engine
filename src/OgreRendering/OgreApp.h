#ifndef OGREIMPL_APP_H
#define OGREIMPL_APP_H

#include <Ogre.h>
#include <OgreApplicationContext.h>
#include <OgreRTShaderSystem.h>
#include <OgreInput.h>

#include <vector>

#include "Transform.h"

namespace OgreImpl
{

class OgreTransformListener;

class OgreApp : public OgreBites::ApplicationContext, public OgreBites::InputListener
{
private:
    std::vector<std::shared_ptr<OgreTransformListener>> _movableObjects;
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