/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Tue Feb  4 2014
 * 
 */



#ifndef _IMAGECONTENT_HEADER_H
#define _IMAGECONTENT_HEADER_H

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "WindowContent.hpp"
namespace gui
{
   class ImageContent : public WindowContent
   {
   public :
      ImageContent();
      virtual ~ImageContent();
      virtual void onTransition();
      virtual void display();

   private :
      GLuint _vbo;
      GLuint _ibo;
      sf::Shader _shader;
      GLuint _vao;      
   };
}
#endif
