#include <cstdlib>
#include <stack>
#include <vector>
#include <GL/glew.h>
#define GLM_SWIZZLE
#include <glm/glm.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "WindowView.hpp"
namespace gui
{
/**
 * @brief Create the opengl context that we will need
 * later during the construction of the WindowView.
 * @return the ContextSetting generated
 */
    sf::ContextSettings WindowView::getInitialContext()
    {
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 3;
	settings.minorVersion = 0;

	return settings;
    }

/**
 * @brief Construct a window with a specified size
 * @param width the initial width of the WindowView
 * @param height the initial height of the WindowView
 */
    WindowView::WindowView(int width, int height,
			   const std::string &title):utils::OpenglObject(),
	_window(sf::VideoMode(width,height),title,
		sf::Style::Default,getInitialContext()),
	_model(new WindowModel)
    {
	_window.setVerticalSyncEnabled(true);
	
	// glewExperimental=true;
	// if (glewInit() != GLEW_OK) 
	// {
	//     std::cerr<<"Failed to initialize GLEW"<<std::endl;
	//     exit(-1);
	// }

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    }

    WindowView::~WindowView()
    {
	delete _model;
    }

/**
 * @brief Display a windowView untils the
 * programm quits and handle the event.
 */
    void WindowView::beginMainLoop()
    {
	while(_window.isOpen())
	{
	    sf::Event event;
	    while(_window.pollEvent(event))
	    {
            
		switch(event.type)
		{
		    case sf::Event::Closed:
			_window.close();
			break;
		    case sf::Event::Resized:		
			glViewport(0, 0, event.size.width,
				   event.size.height);
			break;
		    case sf::Event::KeyPressed:
			if(event.key.code == sf::Keyboard::A)
			{
			    _model->nextContent();
			}
			    
			break;
		    default:
			break;
		
		}
	    }
	    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	    (_model->getCurrentContent())->display();
	    _window.display();
	}

    }

/**
 * @brief resize the window
 * @param width the new width of the window
 * @param height the new height of the window
 */
    void WindowView::resize(unsigned int width,unsigned int height)
    {
	_window.setSize(sf::Vector2u(width,height));
    }

    WindowModel * WindowView::getModel()
    {
	return _model;
    }

}
