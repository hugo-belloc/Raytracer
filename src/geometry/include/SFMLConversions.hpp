
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


#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/OpenGL.hpp>
#include "utils_glm.hpp"


// namespace geometry
// {
namespace conversions
{
    // inline sf::Vector3f sfmlToGlm(const glm::vec3 & vec)
    // {
    // 	return sf::Vector3f(vec.x,vec.y,vec.z);
    // }

    // inline sf::Vector3f glmToSfml(const glm::vec3 & vec)
    // {
    // 	return glm::vec3(vec.x,vec.y,vec.z);
    // }

    inline sf::Color glmToColorSfml(const glm::vec3 & vec)
    {
	glm::vec3 vecScale=vec*255.f;
	float x=(vecScale.x>255)?255:vecScale.x;
	float y=(vecScale.y>255)?255:vecScale.y;
	float z=(vecScale.z>255)?255:vecScale.z;
	return sf::Color((unsigned int)x,
			 (unsigned int)y,
			 (unsigned int)z);
    }
}
// }

#endif
