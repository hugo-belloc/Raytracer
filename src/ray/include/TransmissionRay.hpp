/**
 * @author Hicham Benjelloun <hicham.benjelloun@ecole.ensicaen.fr>
 * @date Sat Feb  22 2014
 * 
 */

/**
 * @file TransmissionRay.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _TRANSMISSIONRAY_HEADER_H
#define _TRANSMISSIONRAY_HEADER_H

#include <iostream>
#include "utils_glm.hpp"
#include "Ray.hpp"

namespace ray
{
   class TransmissionRay : public Ray
   {
   public :
      TransmissionRay(const glm::vec3 &origin,const glm::vec3 & direction, float tmin, float tmax);
      virtual ~TransmissionRay();
      virtual glm::vec3 getColor() const;
   
   private:
      float transmissionCoefficient;

   };

}
#endif
