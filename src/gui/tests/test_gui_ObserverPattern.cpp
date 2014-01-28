/**
  * @file test_guiObserverPattern.cpp
  *
  * This the class gui::Observer and gui::Observable
  * by implementing a dummy version of the pattern.
  * Note : for easy testing purpose all the class used for testing
  * are in the same file. (I know it is bad)
  *
  */
#include <iostream>
#include <string>
#include "Observer.hpp"
#include "Observable.hpp"

using namespace std;
using gui::Observer;
using gui::Observable;

class DummyEvent
{
private :
    string _message;

public :
    DummyEvent(const string & message):_message(message)
    {}

    string getMessage() const
    {
        return _message;
    }
};

class DummyObserver : public Observer<DummyEvent>
{
private :
    string _name;

public :
    DummyObserver(const string & name):_name(name)
    {}

    virtual ~DummyObserver()
    {}

    virtual void update(const DummyEvent &event)
    {
        cout<<"DummyObserver "<<_name<<" has been updated."<<endl;
        cout<<"Event :"<<event.getMessage()<<endl;
    }
};

class DummyObservable : public Observable<DummyEvent>
{
private :
    string _name;
    int _state;

public :
    DummyObservable(const string & name):_name(name),_state(0)
    {}

    virtual ~DummyObservable()
    {}

    void stateChange()
    {
        cout<<"DummyObservable "<<_name<<" state change from "<<_state;
        cout<<" to "<<++_state<<endl<<endl;
        fireEvent(DummyEvent("DummyObservable "+_name+" state change"));
        cout<<endl;
    }
};

int main()
{
    DummyObservable observable_01("observable_01");

    DummyObserver observer_a("observer_a");
    observable_01.addObserver(&observer_a);
    DummyObserver observer_b("observer_b");
    observable_01.addObserver(&observer_b);

    observable_01.stateChange();

    DummyObserver observer_c("observer_c");
    observable_01.addObserver(&observer_c);
    observable_01.stateChange();

    observable_01.deleteObserver(&observer_a);
    observable_01.deleteObserver(&observer_b);
    observable_01.stateChange();



    return 0;
}
