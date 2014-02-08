

/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Tue Feb  4 2014
 * 
 */



#include "Vao.hpp"

using namespace std;

namespace glutils
{
   void makeSimpleVAO(GLuint *vao,GLuint vbo,GLuint ibo)
   {
      glGenVertexArrays(1, vao);
      glBindVertexArray(*vao);

      glBindBuffer(GL_ARRAY_BUFFER,vbo);
      glEnableVertexAttribArray(0);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

      glBindVertexArray(0);
      glBindBuffer(GL_ARRAY_BUFFER, 0);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
      glDisableVertexAttribArray(0);

   }

   void makeTextureVAO(GLuint *vao,GLuint positionBuffer,
		       GLuint texCoordsBuffer,GLuint ibo)
   {
      glGenVertexArrays(1, vao);
      glBindVertexArray(*vao);

      glBindBuffer(GL_ARRAY_BUFFER,positionBuffer);
      glEnableVertexAttribArray(0);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

      glBindBuffer(GL_ARRAY_BUFFER,texCoordsBuffer);
      glEnableVertexAttribArray(1);
      glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

      glBindVertexArray(0);
      glBindBuffer(GL_ARRAY_BUFFER, 0);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

      glDisableVertexAttribArray(0);
      glDisableVertexAttribArray(1);

   }
}