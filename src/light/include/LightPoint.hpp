
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file Light.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _LIGHT_HEADER_H
#define _LIGHT_HEADER_H

#include "utils_glm.hpp"

namespace light
{
    class LightPoint
    {
    public :
	LightPoint(float power,const glm::vec3 & position,
		   const glm::vec3 & color,float fallOff=1.0);
	glm::vec3 powerAt(glm::vec3 point);

	float getPower()const;
	void setPower(float power);
	glm::vec3 getPosition() const;
	void setPosition(const glm::vec3 & position);
	glm::vec3 getColor() const;
	void setColor(const glm::vec3 & color);
	float getFallOff()const;
	void setFallOff(float fallOff);

	void displayTTY() const;

    private :
	float  _power;
	glm::vec3 _position;
	glm::vec3 _color;
	float _fallOff;

    };
}
#endif
