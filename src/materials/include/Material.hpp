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

class Material
{
public :
   Material();
   glm::vec3 computeBRDF(const ray::Ray &orig,
      const Intersect & inter);

private :
   MaterialProperties properties;
};

#endif
