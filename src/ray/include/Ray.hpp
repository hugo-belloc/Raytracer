/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sat Feb  8 2014
 * 
 */

/**
 * @file Ray.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _RAY_HEADER_H
#define _RAY_HEADER_H

#include <iostream>
#include "utils_glm.hpp"

namespace ray
{
   class Ray
   {
   public :
      Ray(const glm::vec3 &origin,const glm::vec3 & direction,float tmin, float tmax, int bounces, int mri = 1.0);
      virtual ~Ray();
      glm::vec3 operator()(float t) const;
      Ray & operator=(const Ray & ray);
      int getBounces() const;
      void setBounces(int);
      void setTmin(float newTmin)const ;
      float getTmin()const;
      void setTmax(float newTmax)const ;
      float getTmax()const;
      void displayTTY()const;
      glm::vec3 getOrigin()const;
      void setOrigin(const glm::vec3 & origin);

      glm::vec3 getDirection()const;
      float getMRI() const;

      virtual glm::vec3 getColor() const;

   private :
      glm::vec3 _origin;
      glm::vec3 _direction;
      mutable float _tmin;
      mutable float _tmax;
      int _bounces;
      int _mri;
   };

}
#endif
