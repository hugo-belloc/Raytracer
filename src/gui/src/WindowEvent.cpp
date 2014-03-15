#include "WindowEvent.hpp"
namespace gui
{
    
    /**
     * Construct a WindowEvent
     * @param state indicate whether the event
     * is due to a Key being pressed or a key being released
     * @param key give the key code
     */
    WindowEvent::WindowEvent(const KeyState & state,
			     const sf::Keyboard::Key& key):
	_state(state),_key(key)
    {}

    /**
     * Give access to the event Key
     * @return the key
     */
    sf::Keyboard::Key WindowEvent::getKey() const
    {
	return _key;
    }

    /**
     * Give access to the event state (release or pressed)
     * @return the state
     */
    KeyState WindowEvent::getState() const
    {
	return _state;
    }
}
