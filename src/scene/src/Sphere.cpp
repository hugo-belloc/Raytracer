
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sat Feb  8 2014
 * 
 */

/**
 * @file Sphere.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "Quadratic.hpp"
#include "Sphere.hpp"

using namespace std;

namespace scene
{

    Sphere::Sphere(const glm::vec3 &center,float radius):/*Shape(),*/_center(center),_radius(radius)
    {}

    Sphere::~Sphere()
    {}
    void  Sphere::setCenter(const glm::vec3 &center)
    {
	_center=center;
    }

    glm::vec3  Sphere::getCenter()const
    {
	return _center;
    }

    float  Sphere::getRadius()const 
    {
	return _radius;
    }

    void  Sphere::setRadius(float radius)
    {
	_radius=radius;
    }

    bool Sphere::intersect(const ray::Ray & ray,
		   Intersection & intersection)const 
    {
	glm::vec3 dir=ray.getDirection();
	glm::vec3 oriToCenter=ray.getOrigin()-_center;
	float a=glm::dot(dir,dir);
	float b=2*glm::dot(dir,oriToCenter);
	float c=glm::dot(oriToCenter,oriToCenter)-_radius*_radius;
	math::Quadratic equation(a,b,c);
	float tInterMin,tInterMax;
	bool isIntersection=equation.solve(tInterMin,tInterMax);
	
	//if the first solution is not between tmin and tmax
	//we take the other one
	float tSol=tInterMin;
	if(tSol<ray.getTmin() || tSol>ray.getTmax())
	{
	    tSol=tInterMax;
	}

	isIntersection = isIntersection &&
	    tSol>=ray.getTmin() && 
	    tSol<=ray.getTmax();
	if(isIntersection)
	{
	    glm::vec3 interPoint=ray(tSol);
	    glm::vec3 normal=glm::normalize(interPoint-_center);
	    intersection.setPoint(interPoint);
	    intersection.setNormal(normal);
	}
	return isIntersection;   
    }

    void Sphere::displayTTY()const
    {
	cout<<"Sphere"<<"[Center="<<_center;
	cout<<",Radius="<<_radius<<"]"<<endl;
    }
}
