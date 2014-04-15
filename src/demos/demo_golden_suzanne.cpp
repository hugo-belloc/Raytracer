
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


#define WIDTH 300
#define HEIGHT 300


int main()
{
    gui::WindowView *view =new WindowView(WIDTH,HEIGHT,"Raytracer");

    camera::PinholeCamera *cam=
	new camera::PinholeCamera(vec3(-4,0,0),vec3(0,0,0),
				  vec3(0,0,1),0.1,1000.f,WIDTH,
				  HEIGHT,45.f);
   
    scene::Scene * scene=new scene::Scene(cam);

    Mesh * suzanne=new Mesh;
    suzanne->loadFromOBJFile("etc/suzanne.obj");
    suzanne->updateBBox();
    Material *matSuzanne=new Material(vec3(0.6,0.6,0.05),0.8,0);
    Object * objSuzanne = new Object(suzanne,matSuzanne,
				    vec3(0,0,0),vec3(180,-30,90),
				    vec3(0.8));
    scene->addObject(objSuzanne);

    scene::Sphere *sphere1=new scene::Sphere(vec3(0,0,16),12);
   materials::Material *redDiffuse=
       new Material(vec3(5),0,0,0);
   scene::Object *redSphere=new Object(sphere1,redDiffuse,vec3(0),vec3(0,0,90));
   scene->addObject(redSphere);

    // Mesh * ceiling=new Mesh;
    // ceiling->loadFromOBJFile("etc/plan.obj");
    // ceiling->updateBBox();
    // Material *matCeiling=new Material(vec3(1),0,0);
    // Object * objCeiling = new Object(ceiling,matCeiling,
    // 				   vec3(0,0,2),vec3(180,0,0),
    // 				  vec3(8);
    // scene->addObject(objCeiling);

     Mesh * ground=new Mesh;
    ground->loadFromOBJFile("etc/plan.obj");
    ground->updateBBox();
    Material *matGround=new Material(vec3(1),0,0);
    Object * objGround = new Object(ground,matGround,
    				   vec3(0,0,-0.6),vec3(0,0,0),
    				  vec3(5));
    scene->addObject(objGround);


    LightPoint *light=new LightPoint(9,vec3(-5,0,0.5),vec3(1,0.7,0.7),1);    
    LightPoint *light2=new LightPoint(6,vec3(-5,0,-0.05),vec3(0.7,0.7,1),1);

    scene->addLightPoint(light);
    scene->addLightPoint(light2);

    WindowController controller(view,scene);
    controller.activate();   

    return 0;
}
