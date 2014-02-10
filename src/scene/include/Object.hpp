
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file Object.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _OBJECT_HEADER_H
#define _OBJECT_HEADER_H

#include "utils_glm.hpp"
#include "Ray.hpp"
#include "Material.hpp"
#include "Shape.hpp"

namespace scene
{
   class Object
   {
   public :
      Object(scene::Shape * shape,
	    materials::Material * material);
      ~Object();
      bool intersect(const ray::Ray & ray,
		     Intersection & intersection)const;
      materials::Material * getMaterial()const;
      
      void diplayTTY()const;

   private :
      scene::Shape * _shape;
      materials::Material * _material;
   };
}
#endif
