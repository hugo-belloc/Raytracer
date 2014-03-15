#ifndef WINDOWEVENT_HPP
#define WINDOWEVENT_HPP

#include <iostream>
#include <SFML/Window/Keyboard.hpp>
namespace gui
{

/**
 * Show whether 
 */
enum KeyState
{
    KEY_PRESSED,
    KEY_RELEASE
};

/**
 * Class that contains a Keyboard Event.
 */
class WindowEvent
{
public :
    WindowEvent(const KeyState & state,
		const sf::Keyboard::Key & key);
    sf::Keyboard::Key getKey() const;
    KeyState getState() const;
    

private :
    KeyState _state;
    sf::Keyboard::Key _key;
    
};

}

#endif // WINDOWEVENT_HPP
