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

   enum RayType
   {
      CameraRay=1,
      ShadowRay=0
   };

   /**
    * This class represents a ray in the modelisation
    * in short, a ray is a point + a direction.
    */
   class Ray
   {
   public :
      Ray(const glm::vec3 &origin,const glm::vec3 & direction,
	  RayType type,float tmin, float tmax);
      virtual ~Ray();
      glm::vec3 operator()(float t) const;
      Ray & operator=(const Ray & ray);
      int getBounces() const;
      void setTmin(float newTmin)const ;
      float getTmin()const;
      void setTmax(float newTmax)const ;
      float getTmax()const;
      void displayTTY()const;
      glm::vec3 getOrigin()const;
      glm::vec3 getDirection()const;

   private :
      glm::vec3 _origin;
      glm::vec3 _direction;
      RayType _type;
      mutable float _tmin;
      mutable float _tmax;
      int _bounces;
   };

}
#endif
