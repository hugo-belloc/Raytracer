/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Thu Mar 13 2014
 * 
 */

/**
 * @file RasterisationContent.hpp
 */


#ifndef _RASTERISATIONCONTENT_HEADER_H
#define _RASTERISATIONCONTENT_HEADER_H

#include "Scene.hpp"
#include "WindowContent.hpp"

namespace gui
{
   /**
    * Class to display a scene with the rasterisation
    * engine.
    */
   class RasterisationContent : public WindowContent
   {
   public :
      RasterisationContent(const scene::Scene  & scene);
      virtual ~RasterisationContent();      
      virtual void onTransition();
      virtual void display();

   private :
      const scene::Scene & _scene;
   };
}
#endif
