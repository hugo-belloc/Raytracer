/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file Camera.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "Camera.hpp"

using namespace std;

namespace camera
{

   Camera::Camera(glm::vec3 position,glm::vec3 target,
		  glm::vec3 up,float nearPlan,float farPlan,
		  unsigned int width, unsigned int height) :
      _position(position),_target(target),_up(up),
      _nearPlan(nearPlan),_farPlan(farPlan),
      _width(width),_height(height)
   { }

   Camera::~Camera()
   {}

   glm::mat4 Camera::getViewMatrice() const
   {
      return glm::lookAt(getPosition(),getTarget(),getUp());
   }
     
   glm::mat4 Camera::getViewPerspectiveMatrice()const
   {
      return getViewMatrice()*getPerspectiveMatrice();
   }

   void Camera::setPosition(const glm::vec3 & pos)
   {
      _position=pos;
   }

   glm::vec3 Camera::getPosition() const
   {
      return _position;
   }

   void Camera::setTarget(const glm::vec3 & target)
   {
      _target=target;
   }

   glm::vec3 Camera::getTarget() const
   {
      return _target;
   }

   void  Camera::setUp(const glm::vec3 & up)
   {
      _up=up;
   }

   glm::vec3 Camera::getUp()const
   {
      return _up;
   }
   
   void Camera::setNearPlan(float nearPlan)
   {
      _nearPlan=nearPlan;
   }

   float Camera::getNearPlan() const
   {
      return _nearPlan;
   }

   void Camera::setFarPlan(float farPlan)
   {
      _farPlan=farPlan;
   }

   float Camera::getFarPlan() const
   {
      return _farPlan;
   }

//
   void Camera::setHeight(unsigned int height)
   {
      _height=height;
   }

   unsigned int Camera::getHeight() const
   {
      return _height;
   }

   void Camera::setWidth(unsigned int width)
   {
      _width=width;
   }

   unsigned int Camera::getWidth() const
   {
      return _width;
   }

}
