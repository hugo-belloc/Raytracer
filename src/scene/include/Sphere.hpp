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
#include "utils_glm.hpp"

class Sphere
{
public :
   Sphere(glm::vec3 center,float radius);
   void setCenter(glm::vec3 center);
   glm::vec3 getCenter();
   float getRadius();
   void setRadius(float radius);
   //Intersection intersect(const Ray & ray);

private :
   glm::vec3 _center;
   float _radius;
};

#endif
