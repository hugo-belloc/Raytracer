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
      camera->setFocalPlan(5.0);
      camera->setWidth(width);
      camera->setHeight(height);

      glm::vec3 cameraInitialPosition(camera->getPosition());

      //for each pixel
      for(unsigned int i=0;i<width;++i)
	 {

	    for(unsigned int j=0;j<height;++j)

	       {
		  glm::vec3 color(0,0,0);      

		  // Pixel center position
		  ray::Ray initialRay=camera->generateRay(i,j);
		  initialRay.setBounces((int)bounces);
		  color+=scene.getColor(initialRay);

		  // DOF
		  glm::vec3 view(glm::normalize(camera->getTarget()-camera->getPosition()));

		  glm::vec3 u = glm::cross(view , camera->getUp() );
		  u = glm::normalize(u);
		  glm::vec3 v = -glm::cross( u, view) ;
		  v = glm::normalize(v);

		  float r = 1.0;

		  for(int i = 0 ; i < 25 ; i++)
		     {
			float di = rand()/float(RAND_MAX+1.0);
			float dj = rand()/float(RAND_MAX+1.0);
			glm::vec3 newPos(cameraInitialPosition-(r/2)*u-(r/2)*v+r*di*u+r*dj*v);
			camera->setPosition(newPos);

			glm::vec3 pointAimed = newPos + camera->getFocalPlan() * initialRay.getDirection();

			ray::Ray jRay = camera->generateRay(pointAimed);
			jRay.setBounces((int)bounces);
			color+=scene.getColor(jRay);
		     }

		  camera->setPosition(cameraInitialPosition);

		  color/=11;
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
