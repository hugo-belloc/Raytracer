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
 * @date Tue Feb  4 2014
 * 
 */

/**
 * @file Buffers.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _BUFFERS_HEADER_H
#define _BUFFERS_HEADER_H

#include <iostream>
#define GLM_SWIZZLE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <GL/glew.h>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
namespace glutils
{
   void makeVBO(GLuint * vbo,GLfloat * data,unsigned int size);
   void makeIBO(GLuint * ibo,GLuint * indices,unsigned int size);
}

#endif
