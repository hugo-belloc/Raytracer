#ifndef WINDOWVIEW_HPP
#define WINDOWVIEW_HPP

#include <iostream>
#include <SFML/Window.hpp>

#include "Observable.hpp"
#include "WindowEvent.hpp"
#include "WindowModel.hpp"

namespace gui
{
/**
 * @brief This class contains a view of
 * the main window of the gui.
 */
    class WindowView : public Observable<WindowEvent>//, public 
{

public :

   
    WindowView(int width,int height,const std::string &title="Raytracer");
    virtual ~WindowView();

    void beginMainLoop();
    void resize(unsigned int width,unsigned int height);
    WindowModel * getModel();

private:
    sf::ContextSettings getInitialContext();
    sf::Window _window;
    WindowModel * _model;
};

}
#endif // WINDOWVIEW_HPP
