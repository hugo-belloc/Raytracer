#ifndef LIBRARYDEFINE_HPP
#define LIBRARYDEFINE_HPP

#include <GL/glfw.h>

/**
 * @author Hugo Belloc
 *
 * This file contains a list of custom defined type
 * that depend on the GUI library used. Gives a better
 * compatibilty with others libraries.
 */

namespace gui
{

/**
 * @brief Represents  all possibles
 * inputs from the keyboard.
 */

enum KeyValue
{
    KEY_A= 'A',
    KEY_B= 'B',
    KEY_C= 'C',
    KEY_D= 'D',
    KEY_E= 'E',
    KEY_F= 'F',
    KEY_G= 'G',
    KEY_H= 'H',
    KEY_I= 'I',
    KEY_J= 'J',
    KEY_L= 'L',
    KEY_M= 'M',
    KEY_N= 'N',
    KEY_O= 'O',
    KEY_P= 'P',
    KEY_Q= 'Q',
    KEY_R= 'R',
    KEY_S= 'S',
    KEY_T= 'T',
    KEY_U= 'U',
    KEY_V= 'V',
    KEY_W= 'W',
    KEY_X= 'X',
    KEY_Y= 'Y',
    KEY_Z= 'Z',
    KEY_0= '0',
    KEY_1= '1',
    KEY_2= '2',
    KEY_3= '3',
    KEY_4= '4',
    KEY_5= '5',
    KEY_6= '6',
    KEY_7= '7',
    KEY_8= '8',
    KEY_9= '9',
    KEY_STOP= '.',
    KEY_EXCLAMATION_MARK= '!',
    KEY_QUESTION_MARK= '?',
    KEY_COMA= ',',
    KEY_COLON= ':',
    KEY_SEMI_COLON= ';',
    KEY_SPACE=GLFW_KEY_SPACE,
    KEY_ESC=GLFW_KEY_ESC,
    KEY_UP=GLFW_KEY_UP,
    KEY_DOWN=GLFW_KEY_DOWN,
    KEY_LEFT=GLFW_KEY_LEFT,
    KEY_RIGHT=GLFW_KEY_RIGHT,
    KEY_LSHIFT=GLFW_KEY_LSHIFT,
    KEY_RSHIFT=GLFW_KEY_RSHIFT,
    KEY_LCTRL=GLFW_KEY_LCTRL,
    KEY_RCTRL=GLFW_KEY_RCTRL,
    KEY_LALT=GLFW_KEY_LALT,
    KEY_RALT=GLFW_KEY_RALT,
    KEY_LSUPER=GLFW_KEY_LSUPER,
    KEY_RSUPER=GLFW_KEY_RSUPER,
    KEY_TAB=GLFW_KEY_TAB,
    KEY_ENTER=GLFW_KEY_ENTER,
    KEY_BACKSPACE=GLFW_KEY_BACKSPACE,
    KEY_INSERT=GLFW_KEY_INSERT,
    KEY_DEL=GLFW_KEY_DEL,
    KEY_PAGEUP=GLFW_KEY_PAGEUP,
    KEY_PAGEDOWN=GLFW_KEY_PAGEDOWN,
    KEY_HOME=GLFW_KEY_HOME,
    KEY_END=GLFW_KEY_END,
    KEY_KP_DIVIDE=GLFW_KEY_KP_DIVIDE,
    KEY_KP_MULTIPLY=GLFW_KEY_KP_MULTIPLY,
    KEY_KP_SUBSTRACT=GLFW_KEY_KP_SUBTRACT,
    KEY_KP_ADD=GLFW_KEY_KP_ADD,
    KEY_KP_DECIMAL=GLFW_KEY_KP_DECIMAL,
    KEY_KP_EQUAL=GLFW_KEY_KP_EQUAL,
    KEY_KP_ENTER=GLFW_KEY_KP_ENTER,
    KEY_KP_NUM_LOCK=GLFW_KEY_KP_NUM_LOCK,
    KEY_CAPS_LOCK=GLFW_KEY_CAPS_LOCK,
    KEY_SCROLL_LOCK=GLFW_KEY_SCROLL_LOCK,
    KEY_PAUSE=GLFW_KEY_PAUSE,
    KEY_MENU=GLFW_KEY_MENU,
    KEY_F1= GLFW_KEY_F1,
    KEY_F2= GLFW_KEY_F2,
    KEY_F3= GLFW_KEY_F3,
    KEY_F4= GLFW_KEY_F4,
    KEY_F5= GLFW_KEY_F5,
    KEY_F6= GLFW_KEY_F6,
    KEY_F7= GLFW_KEY_F7,
    KEY_F8= GLFW_KEY_F8,
    KEY_F9= GLFW_KEY_F9,
    KEY_F10= GLFW_KEY_F10,
    KEY_F11= GLFW_KEY_F11,
    KEY_F12= GLFW_KEY_F12
}
#endif // LIBRARYDEFINE_HPP
