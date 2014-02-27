 
#ifndef TRIANGLECONTENT_HEADER_H
#define TRIANGLECONTENT_HEADER_H

#include <iostream>

#define GLM_SWIZZLE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "WindowContent.hpp"
#include "Program.hpp"
namespace gui
{
    /**
     * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
     * @date Mon Feb  3 2014
     * 
     */
    class TriangleContent : public WindowContent
    {
    public :
	TriangleContent();
	virtual ~TriangleContent();
	virtual void onTransition();
	virtual void display();

    private :
	GLuint _vbo;
	GLuint _ibo;
//    sf::Shader _shader;
	glutils::Program _prog;
	GLuint _vao;      
    };
}

#endif
