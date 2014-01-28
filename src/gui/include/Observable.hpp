#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include "Observer.hpp"
#include <set>

/**
 * @file Observer.hpp
 */

namespace gui
{

/**
 * @author Hugo Belloc
 * @brief  A template class of the Observable class of the Observer
 * Design Pattern
 *
 * An interface that represents an object able to emit events
 * and notify to the registered Observers.
 */
template<typename Event>
class Observable
{
private :
    std::set<Observer<Event>*> _observers;
public:
    virtual ~Observable(){}

    /**
     * @brief addObserver allow an Observer to register in
     * order to be notify by an event when the Observable state change
     * @param observer the Observer to register
     */
    virtual void addObserver(Observer<Event> * observer)
    {
        _observers.insert(observer);
    }

    /**
     * @brief deleteObserver cancel the registration of an Observer
     * @param observer the observer to delete
     */
    virtual void deleteObserver(Observer<Event> * observer)
    {
        _observers.erase(observer);
    }

    /**
     * @brief fireEvent notify all the Observer of a change in the Observable
     * state by sending them an event.
     * @param event the event to send : represents the change in the object state.
     */
    virtual void fireEvent(const Event & event)
    {
        typename std::set<Observer<Event> *>::iterator it;
        for(it=_observers.begin();it!=_observers.end();++it)
        {
            (*it)->update(event);
        }
    }
};

}
#endif // OBSERVABLE_HPP
