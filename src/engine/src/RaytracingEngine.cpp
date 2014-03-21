/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @author Hicham Benjelloun <hicham.benjelloun@ecole.ensicaen.fr>
 * @date Mon Feb 10 2014
 * 
 */

/**
 * @file RaytracingEngine.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "RaytracingEngine.hpp"
#include "SFMLConversions.hpp"
using namespace std;

namespace engine
{
   RaytracingEngine::RaytracingEngine(sf::Image *image):_image(image)
   {}

   RaytracingEngine::~RaytracingEngine()
   {}

    void RaytracingEngine::raytrace(scene::Scene & scene,unsigned int bounces)
   {
      unsigned int width=_image->getSize().x;
      unsigned int height=_image->getSize().y;
      camera::Camera * camera=scene.getCamera();
      camera->setWidth(width);
      camera->setHeight(height);

      
      //for each pixel
      for(unsigned int i=0;i<width;++i)
	 {

	    for(unsigned int j=0;j<height;++j)

	       {
		  // Pixel center position



		  ray::Ray initialRay=camera->generateRay(i,j);
		  initialRay.setBounces((int)bounces);
		  glm::vec3 color(0,0,0);

		  color+=scene.getColor(initialRay);
		  // Converting color
		  sf::Color colorSFML = conversions::glmToColorSfml(color);
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

}
