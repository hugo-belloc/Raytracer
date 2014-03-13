/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file RaytracingEngine.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _RAYTRACINGENGINE_HEADER_H
#define _RAYTRACINGENGINE_HEADER_H

#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "ShadowRay.hpp"

namespace engine
{
   class RaytracingEngine
   {
   public :
      RaytracingEngine(sf::Image *image);
      virtual ~RaytracingEngine();
      void raytrace(scene::Scene &scene);
      sf::Image * getImage()const;
      void setImage(sf::Image * image);
   private :
      sf::Image * _image;
   };
}
#endif
