
/**
 * @author Hicham Benjelloun <hicham.benjelloun@ecole.ensicaen.fr>
 * @date Sat Feb 22 2014
 * 
 */

/**
 * @file CameraRay.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */
#include "CameraRay.hpp"

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
   CameraRay::CameraRay(const glm::vec3 & origin ,const glm::vec3 & direction,float tmin, float tmax, int bounces):
      Ray(origin,direction,tmin,tmax,bounces)
   {}

   /**
 * Virtual destructor
 */
   CameraRay::~CameraRay()
   {}
   

   glm::vec3 CameraRay::getColor() const
   {
      glm::vec3 color(0,0,0);
      return color;
   }


}

