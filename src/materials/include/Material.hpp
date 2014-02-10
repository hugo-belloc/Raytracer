/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file Material.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _MATERIAL_HEADER_H
#define _MATERIAL_HEADER_H

#include <string>
#include <map>
#include "utils_glm.hpp"
#include "MaterialProperties.hpp"
#include "Ray.hpp"
namespace materials
{
   class Material
   {
   public :
      Material(const glm::vec3 & color);
      glm::vec3 computeBRDF(const ray::Ray &shadowRay,
			    const glm::vec3 & normal)const;
      void displayTTY()const;

   private :
      MaterialProperties _properties;
   };
}

#endif
