#ifndef ENGINE_ANIMATOR_H
#define ENGINE_ANIMATOR_H

#include<string>

#include <Ogre.h>

#include "Component.h"
#include "StateMachine.h"
#include "Observer.h"

#include "MeshRenderer.h"

namespace OgreImpl
{

class Animator : public Engine::Component
{
private:
    std::shared_ptr<MeshRenderer> _renderer;
    std::shared_ptr<Engine::StateMachine> _stateMachine;
public:
    Animator(std::shared_ptr<Engine::GameObject> obj) : Component(obj) { }

    void start()
    {
        _renderer = getComponent<MeshRenderer>();
        initStateMachine(_stateMachine);
    }

    void update(float deltaTime)
    {
        _stateMachine->update(deltaTime);
    }
private:
    virtual void initStateMachine(std::shared_ptr<Engine::StateMachine>& stateMachine) = 0;
};


class AnimationClip
{
    struct EventPair {
        std::string name;
        float moment;

        bool operator<(EventPair& a) {
            return moment < a.moment;
        }
    };
private:
    Ogre::AnimationState* _ogreAnimation;
    std::vector<EventPair> _events;

    float _previousCallTime;

    float _speed;
    float _blendFactor;
public:
    AnimationClip(Ogre::AnimationState* ogreAnimation, float speed, float blendFactor) :
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


class AnimationState : public Engine::State {
protected:
    std::vector<std::shared_ptr<AnimationClip>> _clips;
    std::vector<std::shared_ptr<Engine::Observer>> _listeners;
private:
    std::map<std::string, std::vector<std::shared_ptr<Engine::Observer>>> _listenerPool;
public:
    AnimationState(std::vector<std::shared_ptr<AnimationClip>> clips) :
        State(), _clips(clips) {}
    AnimationState(std::vector<std::shared_ptr<AnimationClip>> clips, std::vector<std::shared_ptr<Engine::Transition>> transitions) :
        State(transitions), _clips(clips) {}

    void start() override;
    void end() override;
    void update(float deltaTime) override;
    void addListener(std::string eventName, std::shared_ptr<Engine::Observer> listener) { _listeners.push_back(listener); }
};

}

#endif //ENGINE_ANIMATOR_H