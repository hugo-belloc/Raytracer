/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @author Hicham Benjelloun <hicham.benjelloun@ecole.ensicaen.fr>
 * @date Mon Feb 10 2014
 * 
 */


 

#include "RaytracingEngine.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/OpenGL.hpp>

using namespace std;

namespace engine
{
    /**
     * Convert a glm::vec3 in sf::Color.
     * @param the vector to convert.
     */
    inline sf::Color glmToColorSfml(const glm::vec3 & vec)
    {
	glm::vec3 vecScale=vec*255.f;
	float x=(vecScale.x>255)?255:vecScale.x;
	float y=(vecScale.y>255)?255:vecScale.y;
	float z=(vecScale.z>255)?255:vecScale.z;
	return sf::Color((unsigned int)x,
			 (unsigned int)y,
			 (unsigned int)z);
    }

    /**
     * Create a Raytracing engine .
     * @param image an image used to render the scene. (Can be saved
     * after)
     * @param dofEnabled true if Depht of Field is to be enabled, false
     * otherwise
     */
    RaytracingEngine::RaytracingEngine(sf::Image *image,bool dofEnabled,
				       unsigned int samplingDof):
	_image(image),_dofEnabled(dofEnabled),_samplingDof(samplingDof)
    {}

    RaytracingEngine::~RaytracingEngine()
    {}

    void RaytracingEngine::raytrace(scene::Scene & scene,unsigned int bounces)
    {
	unsigned int width=_image->getSize().x;
	unsigned int height=_image->getSize().y;
	camera::Camera * camera=scene.getCamera();
     
	camera->setFocalPlan(5.0);
	camera->setWidth(width);
	camera->setHeight(height);

	glm::vec3 cameraInitialPosition(camera->getPosition());

	glm::vec3 view(glm::normalize(camera->getTarget()-camera->getPosition()));
	glm::vec3 u = glm::cross(view , camera->getUp() );
	u = glm::normalize(u);
	glm::vec3 v = -glm::cross( u, view) ;
	v = glm::normalize(v);

	//for each pixel
	for(unsigned int i=0;i<width;++i)
	{

	    for(unsigned int j=0;j<height;++j)

	    {
		glm::vec3 color(0,0,0);      

		// Pixel center position
		ray::Ray initialRay=camera->generateRay(i,j);
		initialRay.setBounces((int)bounces);

		// DOF

		glm::vec3 pointAimed = cameraInitialPosition + camera->getFocalPlan() * initialRay.getDirection();

		if(_dofEnabled)
		{
		    float r = camera->getAperture();

		    for(unsigned int i = 0 ; i < _samplingDof ; i++)
		    {	
			float di =((rand()%2)?-1:1)*rand()/float(RAND_MAX+1.0);
			float dj =((rand()%2)?-1:1)*rand()/float(RAND_MAX+1.0);
			glm::vec3 newPos(cameraInitialPosition+r*di*u+r*dj*v);
			camera->setPosition(newPos);

			ray::Ray jRay = camera->generateRay(pointAimed);
			jRay.setBounces((int)bounces);
			color+=scene.getColor(jRay);
		    }

		    camera->setPosition(cameraInitialPosition);
		    color/=_samplingDof;
		}
		else
		{
		    color=scene.getColor(initialRay);
		}
		
		  
		// Converting color
		sf::Color colorSFML = glmToColorSfml(color);
		_image->setPixel(i,j,colorSFML);
	       
	    }
	}
    }

    sf::Image * RaytracingEngine::getImage()const
    {
	return _image;
    }

    void RaytracingEngine::setImage(sf::Image * image)
    {
	_image=image;
    }

    /**
     * @return true if the Depth of field effect is
     * activated, false otherwise
     */
    bool RaytracingEngine::getDofEnabled()const
    {
	return _dofEnabled;
    }

    /**
     * Controls if the Depth of field effect is enabled or not
     * @param enabled true if the Depth of field effect is to
     * be enabled false otherwise
     */
    void RaytracingEngine::setDofEnabled(bool enabled)
    {
	_dofEnabled=enabled;
    }

    /**
     * @return the amount of sampling of the engine
     * for the Depth of field effect.
     * 
     */
    unsigned int RaytracingEngine::getSamplingDof()const
    {
	return (unsigned int)_samplingDof;
    }

    /**
     * Controls if the amount of sampling for the Depth of field effect
     * @param samplingDof the new number of sample to use if DOF is activated.
     */
    void RaytracingEngine::setSamplingDof(unsigned int samplingDof)
    {
	_samplingDof=(int)samplingDof;
    }

    
}
