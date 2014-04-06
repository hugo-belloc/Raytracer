/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file PinholeCamera.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _PINHOLECAMERA_HEADER_H
#define _PINHOLECAMERA_HEADER_H

#include "utils_glm.hpp"
#include "Ray.hpp"
#include "Camera.hpp"

namespace camera
{
   class PinholeCamera : public Camera
   {
   public :

      PinholeCamera(glm::vec3 position,glm::vec3 target,
		    glm::vec3 up,float nearPlan,float farPlan,
		    unsigned int width, unsigned int height,float fov,
		    float aperture=0.02);
      virtual ~PinholeCamera();
      
      virtual ray::CameraRay generateRay(unsigned int i,unsigned int j)const;
      ray::CameraRay generateRay(glm::vec3 point) const;
      void setFov(float fov);
      float getFov()const;      
      virtual void updatePerspectiveMatrix()const;

      private :
      float _fov;
   };
}
#endif
