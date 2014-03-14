/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file Material.hpp
 *  
 * Declaration of the Material class.
 */


#ifndef _MATERIAL_HEADER_H
#define _MATERIAL_HEADER_H

#include <string>
#include <map>
#include "utils_glm.hpp"
#include "MaterialProperties.hpp"
#include "Ray.hpp"
#include "Program.hpp"

namespace materials
{
   class Material
   {
   public :
      Material(const glm::vec3 & color);
      glm::vec3 computeBRDF(const ray::Ray &shadowRay,
			    const glm::vec3 & normal)const;
      void displayTTY()const;
      void setUniforms(const utils::Program & prog)const;
       

   private :
      MaterialProperties _properties;
   };
}

#endif
