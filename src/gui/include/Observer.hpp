#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <iostream>

/**
 * @file Observer.hpp
 */
namespace gui
{
/**
 * @author Hugo Belloc
 * @brief A template class of the Observer class of the Observer
 * Design Pattern
 *
 * An interface that represents an object able to receive events
 * (when an instance of a subclass of Observable<Event> is modified)
 */

template <typename Event>
class Observer
{
public :
    virtual ~Observer()
    {}

    /**
     * @brief update let the observer know that the Observable
     *  has been modified.
     *
     * @param event contains information about the change
     */
    virtual void update(const Event & event)=0;
};
}
#endif // OBSERVER_HPP
