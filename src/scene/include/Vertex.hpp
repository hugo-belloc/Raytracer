/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Mon Feb 17 2014
 * 
 */

/**
 * @file Vertex.hpp
 *  
 * Declaration of the Vertex class.
 */


#ifndef _VERTEX_HEADER_H
#define _VERTEX_HEADER_H

#include <iostream>
#include "utils_glm.hpp"

namespace scene
{
  /**
   * Class containing a Vertex
   * position+normal
   *
   * @author Hugo Belloc<hugo.belloc@ecole.ensicaen.fr>
   */
   class Vertex
   {
   public :
      Vertex();
      Vertex(const glm::vec3 & position,
	     const glm::vec3 & normal=glm::vec3(0,0,0));

      const glm::vec3 & getPosition() const;
      const glm::vec3 & getNormal() const;
      void setPosition(const glm::vec3 & position);
      void setNormal(const glm::vec3 & normal);
      void displayTTY();

   private :
      glm::vec3 _position;
      glm::vec3 _normal;
   };
}
#endif
