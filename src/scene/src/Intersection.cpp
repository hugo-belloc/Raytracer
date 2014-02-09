/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sat Feb  8 2014
 * 
 */

/**
 * @file Intersection.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "Intersection.hpp"

using namespace std;

namespace scene
{
    Intersection::Intersection():
      _hitPoint(glm::vec3(0,0,0)),
      _normal(glm::vec3(0,0,0))
   {}

   Intersection::Intersection(const glm::vec3 & hitPoint,
			      const glm::vec3 & normal) :
      _hitPoint(hitPoint),_normal(glm::normalize(normal))
   {}

   glm::vec3 Intersection::getPoint()const
   {
      return _hitPoint;
   }

   glm::vec3 Intersection::getNormal()const
   {
      return _normal;
   }

   void Intersection::setPoint(const glm::vec3 & point)
   {
      _hitPoint=point;
   }

   void Intersection::setNormal(const glm::vec3 & normal)
   {
      _normal=normal;
   }

   Intersection & Intersection::operator=(const Intersection & intersection)
   {
      _hitPoint=intersection._hitPoint;
      _normal=intersection._normal;
      return *this;
   }

    void Intersection::displayTTY()
    {
	cout<<"Intersection"<<"[Point="<<_hitPoint;
	cout<<",Normal="<<_normal<<"]"<<endl;
    }
}
