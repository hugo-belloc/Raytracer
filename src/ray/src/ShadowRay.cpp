
/**
 * @file ShadowRay.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */
#include "ShadowRay.hpp"

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
   ShadowRay::ShadowRay(const glm::vec3 & origin ,const glm::vec3 & direction,float tmin, float tmax, int bounces, int mri):
      Ray(origin,direction,tmin,tmax,bounces,mri)
   {}

   /**
 * Virtual destructor
 */
   ShadowRay::~ShadowRay()
   {}
   


}

