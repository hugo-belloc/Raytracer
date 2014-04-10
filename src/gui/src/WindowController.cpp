#include "WindowController.hpp"
#include "Camera.hpp"
#define GLM_FORCE_RADIANS 


namespace gui
{
    WindowController::WindowController(WindowView *view,
				       scene::Scene * scene):
	_view(view),_scene(scene)
    {
	WindowModel * model=view->getModel();   
	model->addContent(new RasterisationContent(*_scene));
	_raytracingContent = 
	    new RaytracingContent(*_scene);
	model->addContent(_raytracingContent);

	_view->addObserver(this);	
    }

    WindowController::~WindowController()
    {
	delete _scene;
	delete _view;
    }

    void  WindowController::moveSphereCamera(float du,float dv,
					     float dn)
    {
	camera::Camera * camera = _scene->getCamera();
	glm::mat4 matView = camera->getViewMatrix();
	glm::vec4 newPos = glm::inverse(matView)*glm::vec4(du,dv,dn,1);
	glm::vec4 newUp = glm::inverse(matView)*glm::vec4(0,1,0,0);
	camera->setPosition(newPos.xyz*(1/newPos.w));
	camera->setUp(newUp.xyz);
    }

    void WindowController::update(const WindowEvent & event)
    {
	
	WindowModel * model=_view->getModel();
	float step=0.1;
	int increaseSampling=10;

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
		    moveSphereCamera(0,step,0);
		    break;
		case sf::Keyboard::Down :
		    moveSphereCamera(0,-step,0);
		    break;
		case sf::Keyboard::Right :
		    moveSphereCamera(step,0,0);
		    break;
		case sf::Keyboard::Left :
		    moveSphereCamera(-step,0,0);
		    break;
		case sf::Keyboard::Z :
		    moveSphereCamera(0,0,-step);
		    break;
		case sf::Keyboard::D :
		    moveSphereCamera(0,0,step);
		    break;
		case sf::Keyboard::B :
		    if(_raytracingContent->toogleDOF())
			std::cout<<"DOF is now enabled"<<std::endl;
		    else
			std::cout<<"DOF is now disabled"<<std::endl;
		    break;   
		case sf::Keyboard::Add :	
			
		    std::cout<<"DOF sampling is now "<<
			_raytracingContent->increaseDOFSampling(increaseSampling)
			     <<std::endl;
		    break;
		case sf::Keyboard::Subtract :
		    std::cout<<"DOF sampling is now "<<
			_raytracingContent->increaseDOFSampling(-increaseSampling)
			     <<std::endl;
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
