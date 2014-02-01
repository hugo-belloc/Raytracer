#ifndef WINDOWEVENT_HPP
#define WINDOWEVENT_HPP

#include <iostream>
namespace gui
{

enum KeyState
{
    KEY_PRESSED,
    KEY_RELEASE
};

/**
 * @author Hugo Belloc
 * @brief The WindowEvent class
 */
class WindowEvent
{
public :
    WindowEvent(KeyState _state);
    ~WindowEvent();

private :
    KeyState _state;
    std::string _key;
};

}

#endif // WINDOWEVENT_HPP
