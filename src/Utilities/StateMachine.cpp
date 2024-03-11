#include "StateMachine.h"

using namespace Engine;

State::State(std::vector<std::shared_ptr<Transition>> transitions) : _transitions(transitions) {
    for(auto transition : transitions)
            processNewTransition(transition);
}

void State::onEnable()
{
    if(_transitions.size() > 0)
        for(auto transition : _transitions)
            transition->onEnable();
    
    start();
}

void State::updateAll(float deltaTime)
{
    for(auto transition : _transitions)
    {
        transition->update(deltaTime);
    }
    update(deltaTime);
}

void State::addTransition(std::shared_ptr<Transition> transition)
{
    _transitions.push_back(transition);
    processNewTransition(transition);
}

bool State::needTransit(std::shared_ptr<Transition>& completedTransition)
{
    if(_transitions.size() == 0)
        return false;

    for(auto transition : _transitions)
    {
        if(transition->needTransit())
        {
            completedTransition = transition;
            return true;
        }
    }
    return false;
}

StateMachine::StateMachine(std::shared_ptr<State> startState) : _currentState(startState)
{
    _currentState->onEnable();
}

void StateMachine::update(float deltaTime)
{
    _currentState->updateAll(deltaTime);

    std::shared_ptr<Transition> completedTransition;

    if(_currentState->needTransit(completedTransition))
        transit(completedTransition->_nextState);

}

void StateMachine::transit(std::shared_ptr<State> nextState)
{
    nextState->onEnable();
    _currentState = nextState;
}