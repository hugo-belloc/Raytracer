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
 * @date Wed Feb  5 2014
 * 
 */

/**
 * @file utilsTexture2D.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "utilsTexture2D.hpp"

namespace utils
{
   void makeTexture2D(GLuint *textureID,const sf::Image & image)
   {
   
      GLuint width=image.getSize().x;
      GLuint height=image.getSize().y;

      glGenTextures(1,textureID);
      glBindTexture(GL_TEXTURE_2D,*textureID);
      glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,
		   width,height,0,	GL_RGBA,
		   GL_UNSIGNED_BYTE,image.getPixelsPtr());
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		      GL_LINEAR);
      
//      glEnable(GL_TEXTURE_2D);
//      glActiveTexture(GL_TEXTURE0);
      
   }
}
