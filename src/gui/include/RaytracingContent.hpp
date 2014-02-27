/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Tue Feb 11 2014
 * 
 */

/**
 * @file RaytracingContent.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _RAYTRACINGCONTENT_HEADER_H
#define _RAYTRACINGCONTENT_HEADER_H

#include "ImageContent.hpp"
#include "RaytracingEngine.hpp"

namespace gui
{
   class RaytracingContent : public WindowContent
   {
   public :
      RaytracingContent(scene::Scene * scene);
      virtual ~RaytracingContent();
      virtual void onTransition();
      virtual void display();
      void update();
   private :
      sf::Image & initImage(sf::Image & img);
      scene::Scene * _scene;
      sf::Image _image;
      engine::RaytracingEngine _engine;
      ImageContent _content;
   };
}
#endif
