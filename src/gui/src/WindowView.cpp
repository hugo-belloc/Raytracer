#include <cstdlib>
#include <stack>
#include <vector>
#include <GL/glew.h>
#include <GL/glfw.h>
#define GLM_SWIZZLE
#include <glm/glm.hpp>

#include "WindowView.hpp"
namespace gui
{

/**
 * @brief init all the necessary librairies.
 */
void WindowView::init(int width,int height)
{
    if(!glfwInit())
     {
         std::cerr<<"Failed to GLFW"<<std::endl;
	 exit(-1);
     }
     //glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4); // 4x antialiasing
     glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR,3);
     glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 3);
     glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
     if(!glfwOpenWindow(width,height,0,100,0,0,32,0,GLFW_WINDOW))
     {
         std::cerr<<"Failed to open a window"<<std::endl;
         glfwTerminate();
	 exit(-1);
     }

     glewExperimental=true;
     if (glewInit() != GLEW_OK) {
        std::cerr<<"Failed to initialize GLEW"<<std::endl;
	exit(-1);
     }
      // Dark blue background
      glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

}

/**
 * @brief Construct a window with null
 * size.
 */
WindowView::WindowView()
{
   init(0,0);
}

/**
 * @brief Construct a window with a specified size
 * @param width the initial width of the WindowView
 * @param height the initial height of the WindowView
 */
WindowView::WindowView(int width, int height)
{
   init(width,height);
}

WindowView::~WindowView()
{
    glfwTerminate();
}

void WindowView::display()
{
    do
      {
          // Clear the screen
          glClear( GL_COLOR_BUFFER_BIT );

	 // Swap buffers
         glfwSwapBuffers();
    }
    while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS && glfwGetWindowParam( GLFW_OPENED ) );

}

void WindowView::resize(int width,int height)
{
   glfwSetWindowSize(width,height);
}

}
