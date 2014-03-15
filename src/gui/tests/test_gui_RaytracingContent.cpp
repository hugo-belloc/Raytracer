
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Fri Mar 14 2014
 * 
 */

/**
 * @file test_gui_RaytracingContent.cpp
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


#define WIDTH 512
#define HEIGHT 512

#define NUMBER_SPHERES 8
#define X_SPHERES -0.5
#define PI 3.14159265

int main()
{
    gui::WindowView view(WIDTH,HEIGHT);

    PinholeCamera *cam=new PinholeCamera(vec3(-5,0,0),vec3(0,0,0),
    					 vec3(0,0,1),0.001,1000.f,WIDTH,
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

    Mesh * suzanne=new Mesh;
    suzanne->loadFromOBJFile("etc/suzanne.obj");
    Material *matSuzanne=new Material(vec3(1,1,1));
    Object * objSuzanne = new Object(suzanne,matSuzanne,
				     vec3(0,0,0),vec3(180,0,90),
				     vec3(0.5,0.5,0.5));
    scene.addObject(objSuzanne);

    LightPoint *light=new LightPoint(40,vec3(-6,-5,0),vec3(1,1,1),1.0);    
    LightPoint *light2=new LightPoint(20,vec3(-6,5,0),vec3(1,1,1),1.5);

    scene.addLightPoint(light);
    scene.addLightPoint(light2);

    gui::WindowModel * model=view.getModel();   
    model->addContent(new gui::RasterisationContent(scene));
    gui::RaytracingContent * raytracingContent = 
	new gui::RaytracingContent(scene);
    model->addContent(raytracingContent);
    raytracingContent->update();
    view.beginMainLoop();
   
    delete raytracingContent;

    return 0;
}
