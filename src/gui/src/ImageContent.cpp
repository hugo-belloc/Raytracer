
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Tue Feb  4 2014
 * 
 */

#include <iostream>
#define GLM_SWIZZLE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <GL/glew.h>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "Vao.hpp"
#include "Buffers.hpp"
#include "ImageContent.hpp"

namespace gui
{
   ImageContent::ImageContent():_shader()
   {

      _shader.loadFromFile("etc/uniformColor.vert",
			   "etc/uniformColor.frag");
      _shader.setParameter("uniformColor",1.0,1.0,0.0);
      GLfloat positions[]=
	 {
	    -1,-1, 0,
	    -1, 1, 0,
	     1,-1, 0, 
	     1, 1, 0,
	 };

      GLuint indices[]=
	 {
	    0,1,2,
	    1,3,2
	 };

      makeVBO(&_vbo,positions,sizeof(positions));
      makeIBO(&_ibo,indices,sizeof(indices));
      makeSimpleVAO(&_vao,_vbo,_ibo);
      
   }

   ImageContent::~ImageContent()
   {
      glDeleteBuffers(1,&_vbo);
      glDeleteBuffers(1,&_ibo);
      glDeleteVertexArrays(1,&_vao);
   }

   void ImageContent::onTransition()
   {}

   void ImageContent::display()
   {
      sf::Shader::bind(&_shader);
      glBindVertexArray(_vao);
      glDrawElements(GL_TRIANGLES,6, GL_UNSIGNED_INT, 0);
      glBindVertexArray(0);
      sf::Shader::bind(0);
   }


}

