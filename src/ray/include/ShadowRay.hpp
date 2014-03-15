/**
 * @author Hicham Benjelloun <hicham.benjelloun@ecole.ensicaen.fr>
 * @date Sat Feb  22 2014
 * 
 */

/**
 * @file ShadowRay.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _SHADOWRAY_HEADER_H
#define _SHADOWRAY_HEADER_H

#include <iostream>
#include "utils_glm.hpp"
#include "Ray.hpp"

namespace ray
{
   class ShadowRay : public Ray
   {
   public :
      ShadowRay(const glm::vec3 &origin,const glm::vec3 & direction, float tmin, float tmax, int bounces, int mri = 1.0);
      virtual ~ShadowRay();
      virtual glm::vec3 getColor() const;
   };

}
#endif
