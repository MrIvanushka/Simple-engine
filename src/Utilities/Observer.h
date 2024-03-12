#ifndef ENGINE_OBSERVER_H
#define ENGINE_OBSERVER_H

#include <set>

namespace Engine
{

class Observable;

class Observer
{
public:
    virtual ~Observer() = default;
    virtual void handle() = 0;
};

class Observable
{
public:
    virtual ~Observable() = default;
    void Attach(Observer& o) { observers.insert(&o); }
    void Detach(Observer& o)
    {
        observers.erase(&o);
    }
protected:
    void invoke()
    {
        for (Observer* o : observers) {
            o->handle();
        }
    }
private:
    std::set<Observer*> observers;
};

template<typename T>
class ArgObservable;

template<typename T>
class ArgObserver
{
public:
    virtual ~ArgObserver() = default;
    virtual void handle(T arg) = 0;
};

template<typename T>
class ArgObservable
{
public:
    virtual ~ArgObservable() = default;
    void Attach(ArgObserver<T>& o) { observers.insert(&o); }
    void Detach(ArgObserver<T>& o)
    {
        observers.erase(o);
    }
protected:
    void invoke(T arg)
    {
        for (ArgObserver<T>* o : observers) {
            o->handle(arg);
        }
    }
private:
    std::set<ArgObserver<T>*> observers;
};

}

#endif //ENGINE_OBSERVER_H
