/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sat Feb  8 2014
 * 
 */

/**
 * @file Intersection.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _INTERSECTION_HEADER_H
#define _INTERSECTION_HEADER_H

#include "utils_glm.hpp"
namespace scene
{
   class Intersection
   {
   public :
      Intersection();
      Intersection(const glm::vec3 & hitPoint,
		   const glm::vec3 & normal);
      glm::vec3 getPoint()const;
      glm::vec3 getNormal()const;
      void setPoint(const glm::vec3 & point);
      void setNormal(const glm::vec3 & normal);
      Intersection & operator=(const Intersection & intersection);
      void displayTTY();

   private :
      glm::vec3 _hitPoint;
      glm::vec3 _normal;

   };
}
#endif
