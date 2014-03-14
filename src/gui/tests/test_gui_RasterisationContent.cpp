/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Thu Mar 13 2014
 * 
 */

/**
 * @file test_gui_RasterisationContent.cpp
 *  
 * Test for the RasterisationContent class
 */
#include <cmath>
#include "WindowView.hpp"
#include "Mesh.hpp"
#include "Sphere.hpp"
#include "Scene.hpp"
#include "RasterisationContent.hpp"
#include "PinholeCamera.hpp"

#define WIDTH 512
#define HEIGHT 512
#define NUMBER_SPHERES 8
#define X_SPHERES -0.5
#define PI 3.14159265

using namespace std;
using namespace glm;
using namespace camera;
using namespace scene;
using namespace materials;
using namespace light;
using namespace gui;

int main()
{
    gui::WindowView view(WIDTH,HEIGHT);
    gui::WindowModel * model=view.getModel();

    PinholeCamera *cam=new PinholeCamera(vec3(-5,0,0),vec3(0,0,0),
					 vec3(0,1,0),0.001,1000.f,WIDTH,
					 HEIGHT,45.f);
   
    Scene scene(cam);
   
    for(int i=0;i<NUMBER_SPHERES;++i)
    {
       float angle=(2*PI*i)/NUMBER_SPHERES;
       Sphere *sphere=new Sphere(vec3(X_SPHERES,sin(angle),
    				     cos(angle)),0.35);
       Material *material=new Material(vec3(0,
    					   fabs(cos(angle/2)),
    					   fabs(sin(angle/2))));
       Object *object=new Object(sphere,material);
       scene.addObject(object);
    }
   
    // Object* object = new Object(new Sphere(glm::vec3(0,0,0),1.0),
    // 				new Material(vec3(0.8,0.8,0.8)),
    // 				vec3(0,0,0),vec3(180,0,90));
    // scene.addObject(object);

    LightPoint *light=new LightPoint(40,vec3(-6,-5,0),vec3(1,1,1),1.0);    
    LightPoint *light2=new LightPoint(20,vec3(-6,5,0),vec3(1,1,1),1.5);

    scene.addLightPoint(light);
    scene.addLightPoint(light2);
   
    model->addContent(new gui::RasterisationContent(scene));
    view.beginMainLoop();

    return 0;
}
