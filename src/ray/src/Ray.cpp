
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sat Feb  8 2014
 * 
 */

/**
 * @file Ray.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */
#include "Ray.hpp"

using namespace std;



namespace ray
{

/**
 * Constructs a ray.
 *
 * @param origin the point the ray originate from
 * @param direction a vector representing the direction
 * of the ray
 * @param type the type of ray = ShadowRay or CameraRay
 * @param tmax the maximum value during parametrisation
 * @param tmax the minimum value during parametrisation
 */
   Ray::Ray(const glm::vec3 & origin ,const glm::vec3 & direction,
	    RayType type,float tmax, float tmin):
      _origin(origin),_direction(direction),_type(type),
      _tmax(tmax),_tmin(tmin),_bounces((int)type)
   {}

/**
 * Virtual destructor
 */
   Ray::~Ray()
   {}

/**
 * Compute on point coordinate along the ray.
 * by origin+t*direction
 *
 * @param the parameter t of the formula
 * @return the computed coordinate
 */
   glm::vec3 Ray::operator()(float t) const
   {
      return _origin+_direction*t;
   }

/**
 * Return the nomber of bounces left. When it
 * reach 0 the ray should not be launch
 */
   int Ray::getBounces() const
   {
      return _bounces;
   }


   void Ray::setTmax(float newTmax)const 
   {
      _tmax=newTmax;
   }

   void Ray::setTmin(float newTmin)const 
   {
      _tmin=newTmin;
   }

   float Ray::getTmax() const
   {
      return _tmax;
   }
   
   float Ray::getTmin() const
   {
      return _tmin;
   }   
   
   void Ray::display()const
   {
      std::cout<<"["<<"origin="<<_origin;
      std::cout<<",direction="<<_direction<<"]";
   }
   glm::vec3 Ray::getOrigin()
   {
      return _origin;
   }

   glm::vec3 Ray::getDirection()
   {
      return _direction;
   }

}
