
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Tue Feb  4 2014
 * 
 */

/**
 * @file Vao.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _VAO_HEADER_H
#define _VAO_HEADER_H

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
   void makeSimpleVAO(GLuint *vao,GLuint vbo,GLuint ibo);
   void makeTextureVAO(GLuint *vao,GLuint positionBuffer,
		       GLuint texCoordsBuffer,GLuint ibo,
		       GLuint texImageBuffer);
}
#endif
