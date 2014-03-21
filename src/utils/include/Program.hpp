/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Fri Feb 21 2014
 * 
 */

/**
 * @file Program.hpp
 *  
 * Declaration of the Program class
 */


#ifndef _PROGRAM_HEADER_H
#define _PROGRAM_HEADER_H

#include <iostream>
#include <string>
#include "utils_glm.hpp"
#include <GL/glew.h>
#include "OpenglObject.hpp"

namespace utils
{
    /**
     * A class containing a vertex shader and
     * a fragmant shader.
     */
    class Program : public utils::OpenglObject
    {
    public :
	Program();
	Program(const Program & otherProg);
	~Program();
	GLuint getId() const;
	bool isEmpty() const;
	void clear();

	void loadFromFiles(const std::string & vertexSrcPath,
			   const std::string & fragSrcPath);      
	void loadFromMemory(const std::string & vertexShaderCode,
			    const std::string &  fragmentShaderCode);

	void setUniform(const std::string & name, GLint val) const;
	void setUniform(const std::string & name, GLfloat val) const;
	void setUniform(const std::string & name, const glm::vec3 & val) const;
	void setUniform(const std::string & name, const glm::vec4 & val) const;
	void setUniform(const std::string & name, const glm::mat3 & val,
			bool transpose=false) const;
	void setUniform(const std::string & name, const glm::mat4 & val,
			bool transpose=false) const;

	GLint getAttributeLocation(const std::string & name)const;
	GLint getUniformLocation(const std::string & name)const;

    private :	
	bool warnIfEmpty(const std::string & warning)const;

	GLuint _progId;
	bool _empty;
    };
}
#endif
