/**
 * @author Hicham Benjelloun <hicham.benjelloun@ecole.ensicaen.fr>
 * @date Sat Feb  22 2014
 * 
 */

/**
 * @file CameraRay.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _CAMERARAY_HEADER_H
#define _CAMERARAY_HEADER_H

#include <iostream>
#include "utils_glm.hpp"
#include "Ray.hpp"

namespace ray
{
   class CameraRay : public Ray
   {
   public :
      CameraRay(const glm::vec3 &origin,const glm::vec3 & direction, float tmin, float tmax, int bounces, int mri = 1.0);
      virtual ~CameraRay();
   };

}
#endif
