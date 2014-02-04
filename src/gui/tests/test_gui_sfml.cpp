#include <iostream>
#define GLM_SWIZZLE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <GL/glew.h>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

int main()
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;
    sf::Window window(sf::VideoMode(800,600),"My window",sf::Style::Default,settings);
    window.setVerticalSyncEnabled(true);
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    glewExperimental=true;
    if (glewInit() != GLEW_OK) {
        std::cerr<<"Failed to initialize GLEW"<<std::endl;
        return -1;
    }

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    // // Create and compile our GLSL program from the shaders
   
    sf::Shader shader;
    if(!shader.loadFromFile("etc/SimpleVertexShader.vertexshader",
    			    "etc/SimpleFragmentShader.fragmentshader"))
    {
    	std::cerr<<"Could not load the shader!"<<std::endl;
    }

    //declarations to draw a triangle
    static const GLfloat  g_vertex_buffer_data[] =
    	{
    	    -1.0f,-1.0f,0.0f,
    	    1.0f, -1.0f,0.0f,
    	    0.0f, 1.0f ,0.0f,
    	};
    GLuint vertex_buffer;
    glGenBuffers(1,&vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER,vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER,sizeof(g_vertex_buffer_data),g_vertex_buffer_data,GL_STATIC_DRAW);

    //   bool show=true;
    sf::Texture texture;
    if (!texture.create(200, 200))
    {
	std::cerr<<"Could create texture!"<<std::endl;
    }
    sf::Image image;
    image.create(200,200,sf::Color(255,255,255));
    texture.update(image);
    
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            
	    switch(event.type)
            {
		case sf::Event::Closed:
		    window.close();
		    break;
		case sf::Event::Resized:		
		    glViewport(0, 0, event.size.width, event.size.height);
		    break;
		case sf::Event::KeyPressed:
		    if(event.key.code == sf::Keyboard::A)
		    {
//			show=false;
//			window.pushGLStates();
		    }
		    break;
		case sf::Event::KeyReleased:
		    if(event.key.code == sf::Keyboard::A)
		    {
//			show=true;
//			window.popGLStates();
			glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
		    }
		    break;
		default:
		    break;
		
	    }
	}
	
	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Use our shader
	sf::Shader::bind(&shader);
        
	//draw the triangle
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER,vertex_buffer);
	glVertexAttribPointer
	    (
		0,                 
		3,                
		GL_FLOAT,           
		GL_FALSE,          
		0,                 
		(void*)0            
		);
	glDrawArrays(GL_TRIANGLES,0,3);
	glDisableVertexAttribArray(0);
	sf::Shader::bind(NULL);

	window.display();

    }

    // Cleanup VBO
    glDeleteBuffers(1, &vertex_buffer);
    glDeleteVertexArrays(1, &VertexArrayID);

}
