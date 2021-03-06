/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file RaytracingEngine.hpp
 *  
 *
 */


#ifndef _RAYTRACINGENGINE_HEADER_H
#define _RAYTRACINGENGINE_HEADER_H

#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "ShadowRay.hpp"
#define DEFAULT_RES 10
/**
 * Define the differents render engine.
 * Rasterisation and Raytracing.
 */
namespace engine
{
    class RaytracingEngine
    {
    public :
	RaytracingEngine(sf::Image *image,bool dofEnabled=false,
	    unsigned int samplingDof=DEFAULT_RES);
	virtual ~RaytracingEngine();
	void raytrace(scene::Scene &scene,unsigned int bounces=3);
	sf::Image * getImage()const;
	void setImage(sf::Image * image);

	bool getDofEnabled()const;
	void setDofEnabled(bool enabled);
	unsigned int getSamplingDof()const;
	void setSamplingDof(unsigned int samplingDof);
	
	
    private :
	sf::Image * _image;
	bool _dofEnabled;
	unsigned int _samplingDof;
    };
}
#endif
