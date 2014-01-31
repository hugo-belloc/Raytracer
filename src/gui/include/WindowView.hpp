#ifndef WINDOWVIEW_HPP
#define WINDOWVIEW_HPP

#include <iostream>


#include "Observable.hpp"
#include "WindowEvent.hpp"
#include "WindowModel.hpp"

namespace gui
{
/**
 * @brief This class contains a view of
 * the main window of the gui.
 */
class WindowView : public Observable<WindowEvent>
{

public :
    WindowView();
    WindowView(int width,int height);

    virtual ~WindowView();

    void display();
    void resize(int width,int height);

private:
   void init(int width,int height);

    int _width;
    int _height;
};

}
#endif // WINDOWVIEW_HPP
