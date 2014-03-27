#include "WindowController.hpp"
#include "Camera.hpp"
#define GLM_FORCE_RADIANS 


float atan2(float y,float x)
{
    if(x>0)
    {
	std::cout<<"1"<<std::endl;
	return glm::atan(y/x);
    }
    if(x<0 && y>=0)
    {
	std::cout<<"2"<<std::endl;
	return glm::atan(y/x)+M_PI;
    }
    if(x<0 && y<0)
    {
	std::cout<<"3"<<std::endl;
	return glm::atan(y/x)-M_PI;
    }
    if(x==0 && y>0)
    {
	std::cout<<"4"<<std::endl;
	return M_PI/2.f;
    }
    if(x==0 && y<0)
    {
	std::cout<<"5"<<std::endl;
	return -M_PI/2.f;
    }
    std::cout<<"6"<<std::endl;
    return 0;

}

namespace gui
{
    WindowController::WindowController(WindowView *view,
				       scene::Scene * scene):
	_view(view),_scene(scene)
    {
	WindowModel * model=view->getModel();   
	model->addContent(new RasterisationContent(*_scene));
	RaytracingContent * raytracingContent = 
	    new RaytracingContent(*_scene);
	model->addContent(raytracingContent);

	_view->addObserver(this);	
    }

    WindowController::~WindowController()
    {
	delete _scene;
	delete _view;
    }

    glm::vec3 WindowController::sphericalTransform(
	const glm::vec3 & pos,
	float dr,float dphi,float dtheta)
    {
	float r = glm::length(pos);
	float posProjDist = glm::length(glm::vec3(pos.x,pos.y,0));
	float phi = atan2(pos.z,posProjDist);
	float theta = atan2(pos.y,pos.x);

	std::cout<<"pos cart:"<<pos<<std::endl;
	std::cout<<"pos pol:"<<glm::vec3(r,phi,theta)<<std::endl;

	r+=dr;
	phi+=dphi;
	theta+=dtheta;

	glm::vec3 newPosition;
	newPosition.x=r*glm::cos(phi)*glm::cos(theta);
	newPosition.y=r*glm::cos(phi)*glm::sin(theta);
	newPosition.z=r*glm::sin(phi);

	return newPosition;
    }

    void  WindowController::moveSphereCamera(float dr,float dphi,
					     float dtheta)
    {
	camera::Camera * camera = _scene->getCamera();
	glm::vec3 position = camera->getPosition();
	glm::vec3 target = camera->getTarget();
	glm::vec3 diffPos = position-target;
	glm::vec3 newDiff=sphericalTransform(diffPos,dr,dphi,dtheta);
	camera->setPosition(newDiff+target);
    }

    void WindowController::update(const WindowEvent & event)
    {
	
	WindowModel * model=_view->getModel();
	float stepAngle=0.1;
	float stepRadius=0.1;

	if(event.getState()==KEY_RELEASE)
	{
	    switch(event.getKey())
	    {
		case sf::Keyboard::A :		    
		    model->nextContent();
		    break;
		default:
		    break;
	    }
	}
	else
	{
	    switch(event.getKey())
	    {
		case sf::Keyboard::Up :
		    moveSphereCamera(0,stepAngle,0);
		    break;
		case sf::Keyboard::Down :
		    moveSphereCamera(0,-stepAngle,0);
		    break;
		case sf::Keyboard::Right :
		    moveSphereCamera(0,0,stepAngle);
		    break;
		case sf::Keyboard::Left :
		    moveSphereCamera(0,0,-stepAngle);
		    break;
		case sf::Keyboard::Z :
		    moveSphereCamera(-stepRadius,0,0);
		    break;
		case sf::Keyboard::D :
		    moveSphereCamera(stepRadius,0,0);
		    break;
		    
		default:
		    break;
	    }
	}
	
    }
    
    void WindowController::activate()
    {
	_view->beginMainLoop();
    }
}
