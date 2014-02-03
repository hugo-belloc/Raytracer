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
 * @date Mon Jan  6 2014
 * 
 */

/**
 * @file loadShader.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _LOADSHADER_HEADER_H
#define _LOADSHADER_HEADER_H

#include <iostream>
#include <GL/glew.h>
#include <GL/glfw.h>
#define GLM_SWIZZLE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

GLuint LoadShaders(const char * vertex_file_path,
		   const char * fragment_file_path);
#endif
