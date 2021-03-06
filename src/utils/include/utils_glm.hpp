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
 * @file utils_glm.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _UTILS_GLM_HEADER_H
#define _UTILS_GLM_HEADER_H

#include <iostream>
#define GLM_SWIZZLE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/norm.hpp>
#include <glm/gtx/component_wise.hpp>
#include <cmath>

#ifdef __linux__
#define _USE_MATH_DEFINES
#else
	#define M_PI 3.141592653589793
	#define INFINITY 1e8
#endif

inline std::ostream & operator<<( std::ostream & os,
			   const glm::vec3 & vector)
{
   os<<"("<<vector.x<<","<<vector.y<<","<<vector.z<<")";
   return os;
}

inline std::ostream & operator<<( std::ostream & os,
			   const glm::vec4 & vector)
{
   os<<"("<<vector.x<<","<<vector.y<<","<<vector.z<<","<<vector.w<<")";
   return os;
}

inline std::ostream & operator<<( std::ostream & os,
			   const glm::bvec3 & vector)
{
   os<<"("<<std::boolalpha<<vector.x<<","<<vector.y<<","<<vector.z<<")";
   return os;
}

inline glm::vec3 componentProduct(const glm::vec3 & a,const glm::vec3 b)
{
   return glm::vec3(a.x*b.x,a.y*b.y,a.z*b.z);
}

#endif
