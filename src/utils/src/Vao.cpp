

/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Tue Feb  4 2014
 * 
 */



#include "Vao.hpp"

using namespace std;

namespace utils
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
   
    /**
     * Create a VAO with an ibo and 2 vbo , one
     * for the positions and one for the normals.
     */
    void makeNormalVAO(GLuint *vao,GLuint positionBuffer,
			GLuint normalBuffer,GLuint ibo)
    {
	glGenVertexArrays(1,vao);
	glBindVertexArray(*vao);

	glBindBuffer(GL_ARRAY_BUFFER,positionBuffer);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
       
	glBindBuffer(GL_ARRAY_BUFFER,normalBuffer);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ibo);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER,0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
     
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
    }

}
