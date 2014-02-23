/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
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

   void RaytracingEngine::raytrace(scene::Scene & scene)
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
	    ray::Ray currentRay=camera->generateRay(i,j);
	    scene::Intersection inter;
	    if(scene.intersect(currentRay,inter))
	    {
	       glm::vec3 color(0,0,0);
	       glm::vec3 pointHit=inter.getPoint();
	       glm::vec3 normalHit=inter.getNormal();
	       materials::Material * materialHit=inter.getMaterial();	       
	       //for each light
	       for(scene::Scene::iterator_light it=scene.begin();
		   it!=scene.end();++it)
	       {
		 
		  glm::vec3 direction=(*it)->getPosition()-pointHit;
		  //cast a shadow ray
		  ray::Ray shadowRay(pointHit,direction,0.1,
				     camera->getFarPlan());
		  scene::Intersection dummyInter;
		  //if light is not blocked then
		  if(!scene.intersect(shadowRay,dummyInter))
		  {
		     glm::vec3 matColor= materialHit->computeBRDF(shadowRay,
								  normalHit);
		     glm::vec3 lightColor=(*it)->powerAt(pointHit);
		     //cout<<"Mat :"<<matColor<<endl;
		     //cout<<"Light:"<<lightColor<<endl;
		     glm::vec3 lightContribution=componentProduct(matColor,
								  lightColor);
		     color+=lightContribution;
		  }
		  // else
		  // {
		  //    cout<<"noir:"<<i<<","<<j<<endl;
		  // }
	       }
	       sf::Color colorSFML = conversions::glmToColorSfml(color);
	       _image->setPixel(i,j,colorSFML);
	       
	    }
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
