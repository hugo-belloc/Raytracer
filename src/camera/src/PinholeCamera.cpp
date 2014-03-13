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
				 unsigned int width,unsigned int height,float fov) :
	Camera(position,target,up,nearPlan,farPlan,width,height),
	_fov(fov)
	
    {}

    PinholeCamera::~PinholeCamera()
    {}

    glm::mat4 PinholeCamera::getPerspectiveMatrice()const
    {
	float aspectRatio=((float)getWidth())/((float)getHeight());
	return glm::perspective(getFov(),aspectRatio,
				getNearPlan(),getFarPlan());
    }

    ray::CameraRay PinholeCamera::generateRay(unsigned int i,
					unsigned int j) const
    {
	glm::vec3 view = glm::normalize(getTarget() - getPosition()); 

	//Compute the horizontal and vertical vector of the clip plan
	glm::vec3 h = glm::cross( view, getUp() );
	h = glm::normalize(h);
	glm::vec3 v = glm::cross( h, view) ;
	v = glm::normalize(v);
	
	// convert fovy to radians 
	float radFovy = (getFov()*M_PI) / 180;
	float vScale = tan( radFovy / 2 )*getNearPlan();
	float hScale = vScale * (getWidth() / getHeight());
	//Scale the v and h vector
	v*= vScale;
	h*= hScale;
	
	//From the image space to ndc coordonate
	float x=(2/(float)getWidth())*(i+0.5)-1;
	float y=(2/(float)getHeight())*(j+0.5)-1;	
	glm::vec3 pointCoordinates=getPosition()+getNearPlan()*view+
	    h*x+v*y;
	glm::vec3 rayDir=pointCoordinates-getPosition();
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

}
