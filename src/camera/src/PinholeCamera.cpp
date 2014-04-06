/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file PinholeCamera.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "PinholeCamera.hpp"

using namespace std;

namespace camera
{

    PinholeCamera::PinholeCamera(glm::vec3 position,glm::vec3 target,
				 glm::vec3 up,float nearPlan,float farPlan,
				 unsigned int width,unsigned int height,
				 float fov,float aperture) :
	Camera(position,target,up,nearPlan,farPlan,width,height,aperture),
	_fov(fov)
	
    {
	updatePerspectiveMatrix();
    }

    PinholeCamera::~PinholeCamera()
    {}

  

    ray::CameraRay PinholeCamera::generateRay(unsigned int i,
					      unsigned int j) const
    {
	//nds space 
	float x=(2.0f*(float)i)/getWidth()-1.0;
	float y=1.0-(2.0*(float)j)/getHeight();
	
	//homogenous clip space
	glm::vec4 dir_homogenous_clip (x,y,-1.0,1.0);
	
        //projection
	glm::vec4 dir_eye=_inversePerspectiveMatrix*dir_homogenous_clip;
	dir_eye=glm::vec4(dir_eye.xy,-1.0,0.0);

	glm::vec4 dir_world=_inverseViewMatrix*dir_eye;

	ray::CameraRay ray(getPosition(),dir_world.xyz,
			   getNearPlan(),getFarPlan(),2);
	return ray;
    }


    ray::CameraRay PinholeCamera::generateRay(glm::vec3 point) const
    {
	glm::vec3 rayDir=point-getPosition();
	ray::CameraRay ray(getPosition(),rayDir,getNearPlan(),getFarPlan(),5);
	return ray;
    }

   
    
    void PinholeCamera::setFov(float fov)
    {
	_fov=fov;
    }

    float PinholeCamera::getFov() const
    {
	return _fov;
    }

    
    /**
     * Update the perspective matrix and it inverse.
     */
    void PinholeCamera::updatePerspectiveMatrix()const
    {
	float aspectRatio=((float)getWidth())/((float)getHeight());
	_perspectiveMatrix =  glm::perspective(getFov(),aspectRatio,
				getNearPlan(),getFarPlan());    
	_inversePerspectiveMatrix=glm::inverse(_perspectiveMatrix);
    }

}
