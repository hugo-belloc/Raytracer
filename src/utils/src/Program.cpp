/**
 * @file Program.cpp
 *  
 * 
 */

#include <vector>
#include "FileLoader.hpp"

#include "Program.hpp"

using namespace std;


namespace utils
{
/**
 * A basic constructor for a program, does
 * allocate the memory in the GPU. The program
 * must be loaded before being usable.
 */
    Program::Program():_progId(0),_empty(true)
    {
    }

/**
 * Destructor : desallocate the memeory in the
 * VRAM.
 */
    Program::~Program()
    {
	if(!_empty)
	{	
	    glDeleteProgram(_progId);
	}
    }

/**
 * 
 * @return the id of the program
 */
    GLuint Program::getId() const
    {
	return _progId;
    }

/**
 * Check if the program has its vertex and fragment
 * shader loaded into it. If it is true then the
 * program cannot be used as it is.
 * @return true if the Program is empty
 */
    bool Program::isEmpty() const
    {
	return _empty;
    }

/**
 * Initialise the program again by desallocating 
 * and reallocating it.
 */
    void Program::clear()
    {
	glDeleteProgram(_progId);
	_empty=true;
    }

    /**
     * Load the vertex and the fragment shaders from 2
     * files.
     * @param vertexSrcPath the path to the vertex Shader
     * @param fragSrcPath the path to the fragment Shader
     */
    void Program::loadFromFiles(const std::string & vertexSrcPath,
				const std::string & fragSrcPath)      
    {
	utils::FileLoader loader;
	string vertexShaderCode=loader.loadTextFile(vertexSrcPath);
	string fragmentShaderCode=loader.loadTextFile(fragSrcPath);
	loadFromMemory(vertexShaderCode,fragmentShaderCode);  
    }

    /**
     * Load the vertex and the fragment shaders from 2
     * string.
     * @param vertexShaderCode the code of the vertex Shader
     * @param fragmentShaderCode the code of the fragment Shader
     */
    void Program::loadFromMemory(const std::string & vertexShaderCode,
				 const std::string &  fragmentShaderCode)
    {
	
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	GLint Result = GL_FALSE;
	int InfoLogLength;
 
	// Compile Vertex Shader
	char const * VertexSourcePointer = vertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
	glCompileShader(VertexShaderID);
 
	// Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> VertexShaderErrorMessage(InfoLogLength);
	glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
	cerr<<&VertexShaderErrorMessage[0];
 
	// Compile Fragment Shader
	char const * FragmentSourcePointer = fragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
	glCompileShader(FragmentShaderID);
 
	// Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> FragmentShaderErrorMessage(InfoLogLength);
	glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
	cerr<<&FragmentShaderErrorMessage[0];
 
	// Link the program 
	
	_progId= glCreateProgram();
	glAttachShader(_progId, VertexShaderID);
	glAttachShader(_progId, FragmentShaderID);
	glLinkProgram(_progId);
 
	// Check the program
	glGetProgramiv(_progId, GL_LINK_STATUS, &Result);
	glGetProgramiv(_progId, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> ProgramErrorMessage( max(InfoLogLength, int(1)) );
	glGetProgramInfoLog(_progId, InfoLogLength, NULL, &ProgramErrorMessage[0]);
	cerr<< &ProgramErrorMessage[0];
 
	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID); 

	_empty=false;

    }

    /**
     * Set a uniform int attribute in the Program
     * @param name the name of the attribute
     * @param value the value of the attribute
     */ 
    void Program::setUniform(const std::string & name, GLint val) const
    {
	GLint location=getUniformLocation(name);
	glUniform1i(location, val); 
    }

    /**
     * Set a uniform float attribute in the Program
     * @param name the name of the attribute
     * @param val the value of the attribute
     */ 
    void Program::setUniform(const std::string & name, GLfloat val) const
    {
	GLint location=getUniformLocation(name);
	glUniform1f(location, val); 
    }

    /**
     * Set a uniform vec3 attribute in the Program
     * @param name the name of the attribute
     * @param val the value of the attribute
     */ 
    void Program::setUniform(const std::string & name, const glm::vec3 & val) const
    {     
	GLint location=getUniformLocation(name);
	glUniform3fv(location, 1, glm::value_ptr(val));
    }

    /**
     * Set a uniform vec4 attribute in the Program
     * @param name the name of the attribute
     * @param val the value of the attribute
     * @param transpose if the matrice should be transpose before setting
     * it as a uniform
     */ 
    void Program::setUniform(const std::string & name, const glm::vec4 & val) const
    {
	GLint location=getUniformLocation(name);
	glUniform4fv(location, 1, glm::value_ptr(val));
    }

    /**
     * Set a uniform mat3 attribute in the Program
     * @param name the name of the attribute
     * @param val the value of the attribute
     */ 
    void Program::setUniform(const std::string & name, const glm::mat3 & val,
			     bool transpose) const
    {
	GLint location=getUniformLocation(name);
	glUniformMatrix3fv(location, 1, transpose, glm::value_ptr(val));
    }

    /**
     * Set a uniform mat4 attribute in the Program
     * @param name the name of the attribute
     * @param val the value of the attribute
     */ 
    void Program::setUniform(const std::string & name, const glm::mat4 & val,
			     bool transpose) const
    {
	GLint location=getUniformLocation(name);
	glUniformMatrix4fv(location, 1, transpose, glm::value_ptr(val));
    }

    /**
     * Get the location of a given attribute in the vertex Shader.
     *
     * @param name the name of the attribute
     * @return the location of the attribute
     */
    GLint Program::getAttributeLocation(const std::string & name)const
    {
	if(!warnIfEmpty("Could not get the location of an attribute"))
	{
	    GLint location=glGetAttribLocation(_progId,name.c_str());
	    if(location<0)
	    {
		cerr<<"Attribute "<<name<<" does not seem to exist in the Program"<<endl;
	    
	    }
	    return location;
	}
	return -1;
    }

    /**
     * Get the location of a given uniform in the vertex Shader.
     *
     * @param name the name of the uniform
     * @return the location of the uniform
     */
    GLint Program::getUniformLocation(const std::string & name)const
    {
	if(!warnIfEmpty("Could not get the location of a uniform"))
	{
	    GLint location=glGetUniformLocation(_progId, name.c_str());(name.c_str());
	    if(location<0)
	    {
		cerr<<"Uniform "<<name<<" does not seem to exist in the Program"<<endl;
	    
	    }
	 
	    return  location;
	}
	return -1;
    }

    /**
     * A private utily methode, check if the
     * Program is empty. If it is the case warn
     * the user.
     * @param warning the warning tho be displayed 
     * as an error if the Program is empty.
     * @return true if the user has been warned.
     */
    bool Program::warnIfEmpty(const std::string & warning)const
    {
	if(isEmpty())
	{
	    cerr<<"The program is empty :"<<warning<<endl;
	    //exit(-1);
	}
	return isEmpty();
    }
}
