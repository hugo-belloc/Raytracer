
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

#include "Quadric.hpp"
#include "Sphere.hpp"
#include "Ray.hpp"

using namespace std;

Sphere::Sphere(glm::vec3 center,float radius):_center(center),
				      _radius(radius)
{}

void  Sphere::setCenter(glm::vec3 center)
{
    _center=center;
}

glm::vec3  Sphere::getCenter()
{
    return _center;
}

float  Sphere::getRadius()
{
    return _radius;
}

void  Sphere::setRadius(float radius)
{
    _radius=radius;
}

// Intersection  Sphere::intersect(const Ray & ray)
// {
   
// }
