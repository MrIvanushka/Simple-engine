#ifndef OGREIMPL_ANIMATOR_H
#define OGREIMPL_ANIMATOR_H

#include<string>

#include <Ogre.h>

#include "Components/Animator.h"

namespace OgreImpl
{

class OgreAnimationClip : public Engine::IAnimationClip
{
    struct EventPair {
        std::string name;
        float moment;

        bool operator<(EventPair& a) {
            return moment < a.moment;
        }
    };
private:
    Ogre::AnimationState* _ogreAnimation = nullptr;
    std::vector<EventPair> _events;

    float _previousCallTime;

    float _speed;
    float _blendFactor;
public:
    OgreAnimationClip(Ogre::AnimationState* ogreAnimation, float speed, float blendFactor) :
        _ogreAnimation(ogreAnimation), _previousCallTime(0), _speed(speed), _blendFactor(blendFactor) {}

    float duration() const { return _ogreAnimation->getLength(); }
    float speed() const { return _speed; }
    float blendFactor() const { return _blendFactor; }

    void update(float deltaTime, std::vector<std::string>& calledEvents);

    void changeSpeed(float newSpeed) { _speed = newSpeed; }
    void changeBlendFactor(float blendFactor);

    void addEvent(std::string name, float moment);

    void playFromMoment(float time);
    void stop();
};

}

#endif //OGREIMPL_ANIMATOR_H