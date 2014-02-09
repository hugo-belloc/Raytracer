/* -*- c-basic-offset: 3 -*- 
 *
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 * 
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sat Feb  8 2014
 * 
 */

/**
 * @file Sphere.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _SPHERE_HEADER_H
#define _SPHERE_HEADER_H
#include "Shape.hpp"
namespace scene
{
   class Sphere:public Shape
   {
   public :
      Sphere(const glm::vec3& center,float radius);
      virtual ~Sphere();
      void setCenter(const glm::vec3 &center);
      glm::vec3 getCenter()const;
      float getRadius()const;
      void setRadius(float radius);
      virtual bool intersect(const ray::Ray & ray,Intersection & intersection) const;
      virtual void displayTTY()const;

   private :
      glm::vec3 _center;
      float _radius;
   };
}



#endif
