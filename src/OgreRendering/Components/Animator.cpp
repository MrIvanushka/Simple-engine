#include"Animator.h"

using namespace OgreImpl;

void AnimationClip::update(float deltaTime, std::vector<std::string>& calledEvents)
{
    _ogreAnimation->addTime(deltaTime * _speed);
    auto curentCallTime = _ogreAnimation->getTimePosition();

    for (int i = 0; i < _events.size(); i++)
    {
        if (_events[i].moment > _previousCallTime && _events[i].moment < curentCallTime)
            calledEvents.push_back(_events[i].name);
    }
    _previousCallTime = curentCallTime;
}

void AnimationClip::changeBlendFactor(float blendFactor)
{
    if (blendFactor < 0)
        blendFactor = 0;
    else if (blendFactor > 1)
        blendFactor = 1;

    _blendFactor = blendFactor;

    if (_ogreAnimation->getEnabled())
        _ogreAnimation->setWeight(_blendFactor);
}

void AnimationClip::addEvent(std::string name, float moment)
{
    EventPair newPair;
    newPair.name = name;
    newPair.moment = moment;

    _events.push_back(newPair);
    std::sort(_events.begin(), _events.end());
}

void AnimationClip::playFromMoment(float time)
{
    _ogreAnimation->setEnabled(true);
    _ogreAnimation->setTimePosition(time);
}

void AnimationClip::stop()
{
    _ogreAnimation->setEnabled(false);
}

void AnimationState::start()
{
    for (auto clip : _clips)
    {
        clip->playFromMoment(0);
    }
}

void AnimationState::end()
{
    for (auto clip : _clips)
    {
        clip->stop();
    }
}

void AnimationState::update(float deltaTime)
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