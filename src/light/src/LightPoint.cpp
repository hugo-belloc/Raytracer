/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file LightPoint.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "LightPoint.hpp"

using namespace std;

namespace light
{
    /**
     * Construct a punctual light
     * @param power : the power of the light
     * @param position: the position of the light source.
     * @param color : the color of the light source
     * @param fallOff : the fallOff ie a coefficient to module
     * the distance...
     */
   
    LightPoint::LightPoint(float power,const glm::vec3 & position,
			   const glm::vec3 &color,float fallOff):
	_power(power),_position(position),_color(color),_fallOff(fallOff)
    {}

    glm::vec3 LightPoint::powerAt(glm::vec3 point)
    {
	float distance=glm::distance2(point,getPosition())*getFallOff();
	return getColor()*(getPower()/(distance));
    }

    float LightPoint::getPower()const
    {
	return _power;
    }

    void LightPoint::setPower(float power)
    {
	_power=power;
    }

    glm::vec3 LightPoint::getPosition() const
    {
	return _position;
    }

    void LightPoint::setPosition(const glm::vec3 & position)
    {
	_position=position;
    }

    glm::vec3 LightPoint::getColor() const
    {
	return _color;
    }

    void LightPoint::setColor(const glm::vec3 & color)
    {
	_color=color;
    }

    float LightPoint::getFallOff()const
    {
	return _fallOff;
    }

    void LightPoint::setFallOff(float fallOff)
    {
	_fallOff=fallOff;
    }
    

    /**
     * Set the information of a uniform variable of type
     * Light (cf etc/diffuseShader.frag) in a Program
     * @param prog : the program to configure
     * @param uniformName : the name of the uniform variable 
     * to configure
     * @param matViewWorld : the model view matrice 
     */
    void LightPoint::setLightUniforms(utils::Program & prog,
			   const std::string & uniformName,
			   const glm::mat4 & matViewWorld) const
    {
	prog.setUniform(uniformName+".power",_power);
	glm::vec4 lightPosition=matViewWorld*glm::vec4(_position,1.0);
	prog.setUniform(uniformName+".position",lightPosition.xyz);
	prog.setUniform(uniformName+".color",_color);
	prog.setUniform(uniformName+".fallOff",_fallOff);
    }

    /**
     * Function that display the content
     * of the object in the standard output.
     * To be used for debugging purpose
     **/
    void LightPoint::displayTTY() const
    {
	cout<<"LightPoint[Power="<<_power;
	cout<<", Position="<<_position;
	cout<<", Color="<<_color;
	cout<<", FallOff="<<_fallOff<<"]"<<endl;
    }

}

