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
private:

public :
    WindowView();
    virtual ~WindowView();

    void display();
};

}
#endif // WINDOWVIEW_HPP
