#ifndef ENGINE_BASICTRANSITIONS_H
#define ENGINE_BASICTRANSITIONS_H

#include "StateMachine.h"
#include "Observer.h"

namespace Engine
{

class ExitTimeTransition : public Transition
{
private:
    float _duration;
    float _currentTime;
public:
    ExitTimeTransition(std::shared_ptr<State> nextState, float duration) : Transition(nextState), _duration(duration)
    {}

    void onEnable() override
    {
        _currentTime = 0;
    }

    void update(float deltaTime) override
    {
        _currentTime += deltaTime;
    }

    bool needTransit() override
    {
        return _currentTime > _duration;
    }
};


class ParameterTransition : public Transition, public Observer
{
private:
    bool _parameter;
public:
    ParameterTransition(std::shared_ptr<State> nextState) : Transition(nextState)
    {}

    void onEnable() override {
        _parameter = false;
    }

    void handle() override {
        _parameter = true;
    }

    bool needTransit() override
    {
        return _parameter;
    }
    };

}

#endif