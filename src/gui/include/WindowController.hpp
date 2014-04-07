#ifndef WINDOWCONTROLLER_HPP
#define WINDOWCONTROLLER_HPP

#include "utils_glm.hpp"
#include "Observer.hpp"
#include "WindowEvent.hpp"
#include "WindowModel.hpp"
#include "WindowView.hpp"
#include "Scene.hpp"
#include "RaytracingContent.hpp"
#include "RasterisationContent.hpp"

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
    WindowController(WindowView *view,scene::Scene * scene);
    virtual ~WindowController();
    virtual void update(const WindowEvent & event);
    void activate();

private:
    glm::vec3 sphericalTransform(const glm::vec3 & pos,
				 float dr,float dphi,float dtheta);
    void moveSphereCamera(float dr,float dphi,float dtheta);

    gui::WindowView * _view;
    scene::Scene * _scene;
    gui::RaytracingContent * _raytracingContent;

};

}
#endif // WINDOWCONTROLLER_HPP
