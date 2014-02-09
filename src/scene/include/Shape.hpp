/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file Shape.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _SHAPE_HEADER_H
#define _SHAPE_HEADER_H


#include "utils_glm.hpp"
#include "Intersection.hpp"
#include "Ray.hpp"

namespace scene
{
   class Shape
   {
   public :
      virtual ~Shape();
      virtual bool intersect(const ray::Ray & ray,Intersection & intersection)const=0;
      virtual void displayTTY()const=0;
      //later for rasterisation purpose
      //Mesh toMesh() const;

   };
}

#endif
