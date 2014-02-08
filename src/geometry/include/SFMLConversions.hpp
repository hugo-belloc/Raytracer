
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Thu Feb  6 2014
 * 
 */

/**
 * @file SFMLConversions.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _SFMLCONVERSIONS_HEADER_H
#define _SFMLCONVERSIONS_HEADER_H

#include <iostream>
#define GLM_SWIZZLE
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

namespace geometry
{
   namespace conversions
   {
      inline sf::Vector3f sfmlToGlm(const glm::vec3 & vec)
      {
	 return sf::Vector3f(vec.x,vec.y,vec.z);
      }

      inline sf::Vector3f glmToSfml(const glm::vec3 & vec)
      {
	 return glm::vec3(vec.x,vec.y,vec.z);
      }
   }
}

#endif
