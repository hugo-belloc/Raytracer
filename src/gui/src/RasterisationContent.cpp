/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Thu Mar 13 2014
 * 
 */

/**
 * @file RasterisationContent.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */
#include "utils_glm.hpp"
#include "RasterisationContent.hpp"
#include "RasterisationEngine.hpp"

using namespace std;

namespace gui
{

   /**
    * Default constructor.
    */
   RasterisationContent::RasterisationContent(const scene::Scene & scene):
      _scene(scene)
   {}

   /**
    * Default destructor.
    */
   RasterisationContent::~RasterisationContent()
   {}

   void RasterisationContent::onTransition()
   {}

   void RasterisationContent::display()
   {
      engine::RasterisationEngine rasEngine;
      rasEngine.drawScene(_scene);
   }

}
