/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

#include "Camera.hpp"

using namespace std;

namespace camera
{

    /**
     * Constructs a camera.
     * @param position the origin of the camera
     * @param target the place the camera is looking
     * @param up a vector pointing up in the camera view 
     * @param nearPlan the minimum distance where the objects
     * are drawn.
     * @param farPlan the maximum distane where the objects
     * are drawn
     * @param width the width (in pixels) of the image generated
     * with the camera
     * @param height the height (in pixels) of the image generated
     * with the camera
     * @param aperture 
     *
     */
    Camera::Camera(glm::vec3 position,glm::vec3 target,
		   glm::vec3 up,float nearPlan,float farPlan,
		   unsigned int width, unsigned int height,
		   float aperture=0.02) :
	_position(position),_target(target),_up(up),
	_nearPlan(nearPlan),_farPlan(farPlan),
	_width(width),_height(height),_aperture(aperture),
	_viewMatrix(), _inverseViewMatrix(),_perspectiveMatrix(),
	_inversePerspectiveMatrix()
    {
	updateViewMatrix();
    }

    /**
     * Virtual destructor 
     */   
    Camera::~Camera()
    {}

    /**
     * Set the position of the Camera ie the origin of
     * the ray.
     * @param pos the position of the camera
     */
    void Camera::setPosition(const glm::vec3 & pos)
    {
	_position=pos;
	updateViewMatrix();
    }

    /**
     * Give the position of the Camera ie the origin of
     * the ray.
     * @return the position of the camera
     */
    glm::vec3 Camera::getPosition() const
    {
	return _position;
    }

    /**
     * Specifies the point that the camera looks.
     *
     * @param the new target of the camera.
     */
    void Camera::setTarget(const glm::vec3 & target)
    {
	_target=target;
	updateViewMatrix();
    }


    /**
     * @return the point that the camera is aiming at.
     */
    glm::vec3 Camera::getTarget() const
    {
	return _target;
    }

    /**
     * Set the vector whose direction indicate the
     * axis y in the image.
     * @param the new up vector.
     */
    void  Camera::setUp(const glm::vec3 & up)
    {
	_up=up;
	updateViewMatrix();
    }

    /**
     * Return a vector whose direction is pointing toward the
     * axis y in the image.
     */
    glm::vec3 Camera::getUp()const
    {
	return _up;
    }
   
    /**
     * Change the distance between the camera and the
     * near plan. All the objects/vertices with a lesser
     * distance to that plan will not be displayed.
     * @param nearPlan the new nearPlan distance
     */
    void Camera::setNearPlan(float nearPlan)
    {
	_nearPlan=nearPlan;
	updatePerspectiveMatrix();
    }

    /**
     * @return the distance between the camera and the
     * near plan. All the objects/vertices with a lesser
     * distance to that plan will not be displayed.
     */
    float Camera::getNearPlan() const
    {
	return _nearPlan;
    }

    /**
     * Change the distance between the camera and the
     * far plan. All the objects/vertices with a greater
     * distance to that plan will not be displayed.
     * @param farPlan the new far plan distance
     */
    void Camera::setFarPlan(float farPlan)
    {
	_farPlan=farPlan;
	updatePerspectiveMatrix();
    }

   /**
     * @return the distance between the camera and the
     * far plan. All the objects/vertices with a greater
     * distance to that plan will not be displayed.
     */
    float Camera::getFarPlan() const
    {
	return _farPlan;
    }

    void Camera::setFocalPlan(float focalPlan)
    {
	_focalPlan = focalPlan;
    }

    float Camera::getFocalPlan() const
    {
	return _focalPlan;
    }


    void Camera::setHeight(unsigned int height)
    {
	_height=height;
	updatePerspectiveMatrix();
    }

    unsigned int Camera::getHeight() const
    {
	return _height;
    }

    void Camera::setWidth(unsigned int width)
    {
	_width=width;
	updatePerspectiveMatrix();
    }

    unsigned int Camera::getWidth() const
    {
	return _width;
    }
    void Camera::setAperture(float aperture)
    {
	_aperture=aperture;
    }

    float Camera::getAperture()const
    {
	return _aperture;
    }

    /**
     * @return the view matrix of the camera.
     *
     */
    const glm::mat4 & Camera::getViewMatrix() const
    {
	return _viewMatrix;
    }

    const glm::mat4 & Camera::getInverseViewMatrix()const
    {
	return _inverseViewMatrix;
    }
     
    const glm::mat4 & Camera::getPerspectiveMatrix()const
    {
	return _perspectiveMatrix;
    }

    const glm::mat4 & Camera::getInversePerspectiveMatrix()const
    {
	return _inversePerspectiveMatrix;
    }
    

    /**
     * Update the view matrix and it inverse.
     */
    void Camera::updateViewMatrix()const
    {
	_viewMatrix=glm::lookAt(getPosition(),getTarget(),getUp());
	_inverseViewMatrix=glm::inverse(_viewMatrix);
    }

}
