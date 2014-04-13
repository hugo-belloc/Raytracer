/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Tue Feb 11 2014
 * 
 */

/**
 * @file RaytracingContent.cpp
 *  
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

    /**
     * Construct a content used to save a raytraced image 
     * of the scene.
     * @param scene : the scene to be raytraced.
     */
    RaytracingContent::RaytracingContent(scene::Scene & scene):
	_scene(scene),_engineImage(),
	_engine(& initImage(_engineImage),false),_imageContent(initImage2(_scene ))
    { }

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

    /**
     * Update the image by computing 
     * the raytraced render of the scene.
     * Then the image is saved.
     */
    void RaytracingContent::update()
    {
	cout<<"Begining of ray tracing"<<endl;
	_engine.raytrace(_scene);
	_engineImage.saveToFile("save.png");
	_imageContent.setImage(&_engineImage);
	display();
	cout<<"Finish"<<endl;
    }

    /**
     * Toogle the dof of the engine
     * @return the new state of dof ie :
     * true for dof enable, false otherwise.
     */
    bool RaytracingContent::toogleDOF()
    {
	bool dofEnabled = _engine.getDofEnabled();
	dofEnabled = !dofEnabled;
	_engine.setDofEnabled(dofEnabled);
	return dofEnabled;
    }

     /**
     * Change the amount of sampling of the raytracing engine
     * @param toAdd the amount to be added to the current
     * sampling, can be negative. If the new quantity is negative
     * it will be 0.
     * @return the new amount of sampling.
     */
    int RaytracingContent::increaseDOFSampling(int toAdd)
    {
	int sampling =(int)_engine.getSamplingDof();
	sampling+=toAdd;
	sampling = (sampling>0)?sampling:0;
	_engine.setSamplingDof((unsigned int)sampling);

	return sampling;
    }
}
