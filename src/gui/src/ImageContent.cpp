
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
#include "utilsTexture2D.hpp"
#include "ImageContent.hpp"

namespace gui
{
    ImageContent::ImageContent(sf::Image * image):
	_image(image),_shader()
    {
	loadImage();      
    }

    ImageContent::~ImageContent()
    {
	clearImage();
    }

    void ImageContent::clearImage()
    {
	glDeleteBuffers(1,&_positionsBuffer);
	glDeleteBuffers(1,&_indexBuffer);
	glDeleteTextures(1,&_textureImageBuffer);
	glDeleteVertexArrays(1,&_vao);
    }

    void ImageContent::loadImage()
    {
	glEnable(GL_TEXTURE_2D);
	_shader.loadFromFile("etc/simpleTexture.vert",
			     "etc/simpleTexture.frag");
	GLfloat positions[]=
	    {
		-1,-1, 0,
		-1, 1, 0,
		1,-1, 0, 
		1, 1, 0,
	    };
	GLfloat texCoords[]=
	    {
		0,1,
		0,0,
		1,1,
		1, 0
	    };
	GLuint indices[]=
	    {
		0,1,2,
		1,3,2
	    };

	utils::makeVBO(&_positionsBuffer,positions
		       ,sizeof(positions));
	utils::makeVBO(&_texCoordsBuffer,texCoords
		       ,sizeof(texCoords));
	utils::makeIBO(&_indexBuffer,indices,sizeof(indices));
	utils::makeTexture2D(&_textureImageBuffer,*_image);
	utils::makeTextureVAO(&_vao,_positionsBuffer,
			      _texCoordsBuffer,_indexBuffer);
    }
    

    void ImageContent::onTransition()
    {}

    void ImageContent::display()
    {
      
	sf::Shader::bind(&_shader);
	glBindVertexArray(_vao);
	glBindTexture(GL_TEXTURE_2D,_textureImageBuffer);
	glDrawElements(GL_TRIANGLES,6, GL_UNSIGNED_INT, 0);
	glBindTexture(GL_TEXTURE_2D,0);
	glBindVertexArray(0);
	sf::Shader::bind(0);
    }
    void ImageContent::setImage(sf::Image* image)
    {
	clearImage();
	sf::Vector2u sizeImage = image->getSize();
	_image->create(sizeImage.x,sizeImage.y);
	_image->copy(*image,0,0);
	_image->saveToFile("copy.png");
	loadImage();
    }
    
}

