/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Thu Mar 13 2014
 * 
 */

/**
 * @file RasterisationEngine.hpp
 *  
 * Declare the engine class
 */


#ifndef _RASTERISATIONENGINE_HEADER_H
#define _RASTERISATIONENGINE_HEADER_H

#include <SFML/Graphics.hpp>
#include "Scene.hpp"

namespace engine
{
   /**
    * This class call the different opengl
    * procedures to draw the objects of a scene.
    * Must be used in a window !!
    */
   class RasterisationEngine
   {
   public :
      RasterisationEngine();
      virtual ~RasterisationEngine();
      void drawScene(const scene::Scene & scene) const; 
   
      
   };
}
#endif
