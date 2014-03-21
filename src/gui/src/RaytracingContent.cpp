/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Tue Feb 11 2014
 * 
 */

/**
 * @file RaytracingContent.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "RaytracingContent.hpp"


using namespace std;

namespace gui
{
    sf::Image & RaytracingContent::initImage(sf::Image & img)
    {
	unsigned int width =_scene.getCamera()->getWidth();
	unsigned int height =_scene.getCamera()->getHeight();
	img.create(width,height,sf::Color(0,0,0));
	return img;
    }

    sf::Image * initImage2(const scene::Scene & scene)
    {
    	sf::Image* img= new sf::Image;
    	unsigned int width =scene.getCamera()->getWidth();
    	unsigned int height =scene.getCamera()->getHeight();
    	img->create(width,height);
	
    	return img;
	    
    }

    RaytracingContent::RaytracingContent(scene::Scene & scene):
	_scene(scene),_engineImage(),
	_engine(& initImage(_engineImage)),_imageContent(initImage2(_scene ))
    {
    }

    RaytracingContent::~RaytracingContent()
    {}

    void RaytracingContent::onTransition()
    {
	update();
    }

    void RaytracingContent::display()
    {
	_imageContent.display();
    }

    void RaytracingContent::update()
    {
	_engine.raytrace(_scene);
	_engineImage.saveToFile("save.png");
	_imageContent.setImage(&_engineImage);
    }

}
