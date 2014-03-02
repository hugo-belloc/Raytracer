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
 * @file utilsTexture2D.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _UTILSTEXTURE2D_HEADER_H
#define _UTILSTEXTURE2D_HEADER_H

#include <iostream>
#define GLM_SWIZZLE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <GL/glew.h>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

namespace utils
{
   void makeTexture2D(GLuint *textureID,const sf::Image & image);
}

#endif
