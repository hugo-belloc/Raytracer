/**
 * @file main.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#include <iostream>
#include "TriangleContent.hpp"
#include "ImageContent.hpp"
#include "WindowModel.hpp"
#include "WindowView.hpp"
#include "RaytracingContent.hpp"
#include "RasterisationContent.hpp"
#include "WindowController.hpp"

#include "Sphere.hpp"
#include "Mesh.hpp"
#include "PinholeCamera.hpp"
#include "RaytracingEngine.hpp"

using namespace std;
using namespace glm;
using namespace scene;
using namespace camera;
using namespace engine;
using namespace materials;
using namespace light;
using namespace utils;
using namespace gui;


#define WIDTH 500
#define HEIGHT 500

#define R 1.5
#define NUMBER_SPHERES 8
#define X_SPHERES -0.5
#define PI 3.14159265
int main()
{
    gui::WindowView *view =new WindowView(WIDTH,HEIGHT,"Raytracer");

    camera::PinholeCamera *cam=
	new camera::PinholeCamera(vec3(-5,0,0),vec3(0,0,0),
    					 vec3(0,0,1),0.001,1000.f,WIDTH,
    					 HEIGHT,45.f);
   
    scene::Scene * scene=new scene::Scene(cam);

    for(int i=0;i<NUMBER_SPHERES;++i)
    {
	float angle=(2*PI*i)/NUMBER_SPHERES;
	scene::Sphere *sphere=new scene::Sphere(vec3(X_SPHERES,R*sin(angle),
				       R*cos(angle)),0.40);
	materials::Material *material=
	    new Material(vec3(0,fabs(cos(angle/2)),fabs(sin(angle/2))),
			 0.8,(i%3)?0:0.8,1.7);
	scene::Object *object=new Object(sphere,material);
	scene->addObject(object);
    }

    Mesh * suzanne=new Mesh;
    suzanne->loadFromOBJFile("etc/suzanne.obj");
    suzanne->updateBBox();
    Material *matSuzanne=new Material(vec3(0.7,0.7,0.7),0,0);
    Object * objSuzanne = new Object(suzanne,matSuzanne,
				     vec3(0,0,0),vec3(180,0,90),
				     vec3(0.5,0.5,0.5));
    scene->addObject(objSuzanne);

    LightPoint *light=new LightPoint(40,vec3(-6,0,-6),vec3(1,1,1),1.0);    
    LightPoint *light2=new LightPoint(20,vec3(-6,0,7),vec3(1,1,1),1.5);

    scene->addLightPoint(light);
    scene->addLightPoint(light2);

    WindowController controller(view,scene);
    controller.activate();   

    return 0;
}
