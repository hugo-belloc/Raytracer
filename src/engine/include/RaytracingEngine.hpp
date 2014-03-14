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

/**
 * Define the differents render engine.
 * Rasterisation and Raytracing.
 */
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
