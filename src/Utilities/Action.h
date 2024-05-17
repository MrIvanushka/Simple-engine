#ifndef ENGINE_OBSERVER_H
#define ENGINE_OBSERVER_H

#include <set>
#include <functional>
#include <stdexcept>

namespace Engine
{

class ActionInvoker
{
private:
    int _id;
public:
    ActionInvoker(int id) : _id(id) {}

    virtual ~ActionInvoker() = default;

    Action produceAction() const { return Action(_id); }

    template<class... Args>
    ArgAction<Args...> produceAction() const { return ArgAction<Args...>(_id); }

    void invoke(const Action& action) const
    {
        action.invoke(_id);
    }

    template<class... Args>
    void invoke(const ArgAction<Args...>& action, Args... args) const
    {
        action.invoke(_id, args);
    }
};

class Action final
{
private:
    friend class ActionInvoker;

    std::set<std::function<void()>> _listeners;

    int _invokerID;
public:

    void attach(std::function<void()> listener) { _listeners.insert(listener); }

private:
    Action(int invokerID) : _invokerID(invokerID) {}

    void invoke(int id) const
    {
        if (id != _invokerID)
            throw std::logic_error("Trying to invoke foreign Action");

        for(auto& listener : _listeners) {
            listener();
        }
    }
};

template<class... Args>
class ArgAction final
{
private:
    friend class ActionInvoker;

    std::set<std::function<void(Args...)>> _listeners;

    int _invokerID;
public:

    void attach(std::function<void(Args...)> listener) { _listeners.insert(listener); }

private:
    ArgAction(int invokerID) : _invokerID(invokerID) {}

    void invoke(int id, Args... args) const
    {
        if (id != _invokerID)
            throw std::logic_error("Trying to invoke foreign Action");

        for (auto& listener : _listeners) {
            (listener(args), ...);
        }
    }
};

}

#endif //ENGINE_ACTION_H
