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
 * @file Buffers.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#include "Buffers.hpp"

using namespace std;

namespace utils
{
   void makeVBO(GLuint * vbo,GLfloat * data,unsigned int size)
   {
      glGenBuffers(1,vbo);
      glBindBuffer(GL_ARRAY_BUFFER,*vbo);
      glBufferData(GL_ARRAY_BUFFER,size,
		   data,GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER, 0);
   }

   void makeIBO(GLuint * ibo,GLuint * indices,unsigned int size)
   {
      glGenBuffers(1,ibo);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,*ibo);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,size,
		   indices,GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
   }


}
