#ifndef WINDOWCONTROLLER_HPP
#define WINDOWCONTROLLER_HPP

#include "Observer.hpp"
#include "WindowEvent.hpp"
#include "WindowModel.hpp"
#include "WindowView.hpp"

namespace gui
{

/**
 * @author Hugo Belloc
 * @brief Represents the controller of a window in
 * the mvc pattern.
 *
 * This class handle the events and upload the WindowView.
 */
class WindowController : public Observer<WindowEvent>
{
public:
    static WindowController * getInstance();
    virtual ~WindowController();
    void update();

private:
    WindowController();
    WindowController * instance;

    WindowView * _view;
    WindowModel * _model;


};

}
#endif // WINDOWCONTROLLER_HPP
