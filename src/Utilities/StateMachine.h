#ifndef ENGINE_STATEMACHINE_H
#define ENGINE_STATEMACHINE_H

#include <vector>
#include <memory>

namespace Engine
{

class Transition;

class State
{
private:
    std::vector<std::shared_ptr<Transition>> _transitions;
public:
    State() {}

    State(std::vector<std::shared_ptr<Transition>> transitions);

    virtual ~State() = default;

    void onEnable();
    void onDisable();

    void updateAll(float deltaTime);

    void addTransition(std::shared_ptr <Transition> transition);

    bool needTransit(std::shared_ptr<Transition>& completedTransition);
private:
    virtual void start() {}
    virtual void end() {}

    virtual void update(float deltaTime) {}

    virtual void processNewTransition(std::shared_ptr<Transition> transition) {}
};

class Transition
{
private:
    std::shared_ptr<State> _nextState;
public:
    friend class StateMachine;

    Transition(std::shared_ptr<State> nextState) : _nextState(nextState) {}

    virtual ~Transition() = default;

    virtual void onEnable() {}

    virtual void update(float deltaTime) {}

    virtual bool needTransit() = 0;
};

class StateMachine
{
private:
    std::shared_ptr<State> _currentState;

public:
    StateMachine(std::shared_ptr<State> startState);

    void update(float deltaTime);

private:
    void transit(std::shared_ptr<State> nextState);
};

}

#endif