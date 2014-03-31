
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Fri Mar 21 2014
 * 
 */

/**
 * @file OpenglObject.cpp
 *  
 */
#include <SFML/Window.hpp>
#include <GL/glew.h>
#include "OpenglObject.hpp"

namespace utils
{

    bool OpenglObject::_isInitialised=false;

    /**
     * Constructor initialise opengl context the first
     * time it is called. Otherwise it does nothing.
     */
    OpenglObject::OpenglObject()
    {
	if(!_isInitialised)
	{
	    std::cout<<"coucou"<<std::endl;
	    sf::Context context;
	    _isInitialised=true;
	    glewExperimental=true;
	    if (glewInit() != GLEW_OK) 
	    {
		std::cerr<<"Failed to initialize GLEW"<<std::endl;
		exit(-1);
	    }
	    std::cout<<"coucou"<<std::endl;
	}
    }
}
