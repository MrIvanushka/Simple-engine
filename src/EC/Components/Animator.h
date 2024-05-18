#ifndef ENGINE_ANIMATOR_H
#define ENGINE_ANIMATOR_H

#include <string>
#include <vector>
#include <map>

#include "../Component.h"

#include "MeshRenderer.h"
#include "StateMachine.h"
#include "Observer.h"

namespace Engine
{

class Animator : public Engine::Component
{
private:
    std::shared_ptr<MeshRenderer> _renderer = nullptr;
    std::shared_ptr<StateMachine> _stateMachine = nullptr;
public:
    Animator(std::shared_ptr<GameObject> obj, std::shared_ptr<Input> input) : Component(obj, input) { }

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


class IAnimationClip
{
public:
    virtual ~IAnimationClip() = default;

    virtual float duration() const = 0;
    virtual float speed() const = 0;
    virtual float blendFactor() const = 0;

    virtual void update(float deltaTime, std::vector<std::string>& calledEvents) = 0;

    virtual void changeSpeed(float newSpeed) = 0;
    virtual void changeBlendFactor(float blendFactor) = 0;

    virtual void addEvent(std::string name, float moment) = 0;

    virtual void playFromMoment(float time) = 0;
    virtual void stop() = 0;
};


class AnimationState : public Engine::State {
protected:
    std::vector<std::shared_ptr<IAnimationClip>> _clips;
    std::vector<std::shared_ptr<Observer>> _listeners;
private:
    std::map<std::string, std::vector<std::shared_ptr<Observer>>> _listenerPool;
public:
    AnimationState(std::vector<std::shared_ptr<IAnimationClip>> clips) :
        State(), _clips(clips) {}
    AnimationState(std::vector<std::shared_ptr<IAnimationClip>> clips, std::vector<std::shared_ptr<Engine::Transition>> transitions) :
        State(transitions), _clips(clips) {}

    void start() override
    {
        for (auto clip : _clips)
        {
            clip->playFromMoment(0);
        }
    }

    void end() override
    {
        for (auto clip : _clips)
        {
            clip->stop();
        }
    }

    void update(float deltaTime) override
    {
        for (auto clip : _clips)
        {
            std::vector<std::string> calledEvents;

            clip->update(deltaTime, calledEvents);

            for (const auto& calledEvent : calledEvents)
            {
                auto calledObservers = _listenerPool.find(calledEvent);

                if (calledObservers != _listenerPool.end())
                    for (auto calledObserver : calledObservers->second)
                        calledObserver->handle();
            }
        }
    }

    void addListener(std::string eventName, std::shared_ptr<Engine::Observer> listener) { _listeners.push_back(listener); }
};

}

#endif //ENGINE_ANIMATOR_H