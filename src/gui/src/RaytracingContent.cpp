/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Tue Feb 11 2014
 * 
 */

/**
 * @file RaytracingContent.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "RaytracingContent.hpp"


using namespace std;

namespace gui
{
   sf::Image & RaytracingContent::initImage(sf::Image & img)
   {
      unsigned int width =_scene->getCamera()->getWidth();
      unsigned int height =_scene->getCamera()->getHeight();
      img.create(width,height,sf::Color(0,0,100));
      update();
      return img;
   }

   RaytracingContent::RaytracingContent(scene::Scene * scene):
      _scene(scene),_image(),_engine(& initImage(_image)),
      _content(_image)
   {
   }

   RaytracingContent::~RaytracingContent()
   {}

   void RaytracingContent::onTransition()
   {}

   void RaytracingContent::display()
   {
      _content.display();
   }

   void RaytracingContent::update()
   {
      _engine.raytrace(*_scene);
   }

}
