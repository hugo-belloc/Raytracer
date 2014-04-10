/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file Camera.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _CAMERA_HEADER_H
#define _CAMERA_HEADER_H

#include "utils_glm.hpp"
#include "CameraRay.hpp"
namespace camera
{
    class Camera
    {
    public :
	Camera(glm::vec3 position,glm::vec3 target,
	       glm::vec3 up,float nearPlan,float farPlan,
	       unsigned int width, unsigned int height,float aperture);
	virtual ~Camera();
	virtual ray::CameraRay generateRay(unsigned int i,unsigned int j) const=0;
	virtual ray::CameraRay generateRay(glm::vec3 point) const = 0;
    
	//getter and setter
	virtual void setPosition(const glm::vec3 & pos);
	virtual glm::vec3 getPosition()const;
	virtual void setTarget(const glm::vec3 & target);
	virtual glm::vec3 getTarget()const;
	virtual void setUp(const glm::vec3 & up);
	virtual glm::vec3 getUp()const;

	virtual void setNearPlan(float nearPlan);
	virtual float getNearPlan() const;
	virtual void setFarPlan(float farPlan);
	virtual float getFarPlan() const;
	virtual void setFocalPlan(float focalPlan);
	virtual float getFocalPlan() const;

	virtual void setHeight(unsigned int height);
	virtual unsigned int getHeight() const;
	virtual void setWidth(unsigned int width);
	virtual unsigned int getWidth() const;

	virtual void setAperture(float aperture);
	virtual float getAperture()const;

	virtual const glm::mat4 & getViewMatrix()const;
	virtual const glm::mat4 & getInverseViewMatrix()const;
	virtual const glm::mat4 & getPerspectiveMatrix()const;
	virtual const glm::mat4 & getInversePerspectiveMatrix()const;

	virtual void updateViewMatrix()const;
	virtual void updatePerspectiveMatrix()const=0;
    private :
	glm::vec3 _position;
	glm::vec3 _target;
	glm::vec3 _up;
	float _nearPlan;
	float _farPlan;
	float _focalPlan;
	unsigned int _width;
	unsigned int _height;
	float _aperture;
	
    protected :
	mutable glm::mat4 _viewMatrix;
	mutable glm::mat4 _inverseViewMatrix;
	mutable glm::mat4 _perspectiveMatrix;
	mutable glm::mat4 _inversePerspectiveMatrix;
    };
}

#endif
