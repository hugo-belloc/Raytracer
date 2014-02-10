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

   void LightPoint::displayTTY() const
   {
      cout<<"LightPoint[Power="<<_power;
      cout<<", Position="<<_position;
      cout<<", Color="<<_color;
      cout<<", FallOff="<<_fallOff<<"]"<<endl;
   }

}

