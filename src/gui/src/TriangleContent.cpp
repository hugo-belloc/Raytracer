
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Mon Feb  3 2014
 * 
 */

/**
 * @file TriangleContent.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
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
#include "TriangleContent.hpp"
using namespace std;

namespace gui
{
    TriangleContent::TriangleContent():_prog()//_shader()
    {

	/*_shader.loadFromFile("etc/uniformColor.vert",
			     "etc/uniformColor.frag");
			     _shader.setParameter("uniformColor",1.0,1.0,1.0);*/

	_prog.loadFromFiles("etc/uniformColor.vert",
			    "etc/uniformColor.frag");
	_prog.setUniform("uniformColor",glm::vec3(1.0,0,0));
	GLfloat positions[]=
	    {
		-1,-1, 0,
		-1, 1, 0,
		 1,-1, 0 
	    };

	GLuint indices[]=
	    {
		0,1,2
	    };

	glutils::makeVBO(&_vbo,positions,sizeof(positions));
	glutils::makeIBO(&_ibo,indices,sizeof(indices));
	glutils::makeSimpleVAO(&_vao,_vbo,_ibo);
      
    }

    TriangleContent::~TriangleContent()
    {
	glDeleteBuffers(1,&_vbo);
	glDeleteBuffers(1,&_ibo);
	glDeleteVertexArrays(1,&_vao);
    }

    void TriangleContent::onTransition()
    {}

    void TriangleContent::display()
    {
	//sf::Shader::bind(&_shader);
	glUseProgram(_prog.getId());
	_prog.setUniform("uniformColor",glm::vec3(1.0,0.0,0.0));
	glBindVertexArray(_vao);
	glDrawElements(GL_TRIANGLES,3, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	glUseProgram(0);
	//sf::Shader::bind(0);
    }


}

