

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


int main()
{
    gui::WindowView *view =new WindowView(WIDTH,HEIGHT,"Raytracer");

    camera::PinholeCamera *cam=
	new camera::PinholeCamera(vec3(-4,0,0),vec3(0,0,0),
				  vec3(0,0,1),0.1,1000.f,WIDTH,
				  HEIGHT,45.f);
   
    scene::Scene * scene=new scene::Scene(cam);

    Mesh * buddha=new Mesh;
    buddha->loadFromOBJFile("etc/buddha.obj");
    buddha->updateBBox();
    Material *matBuddha=new Material(vec3(1,1,1),0.8,0);
    Object * objBuddha = new Object(buddha,matBuddha,
				    vec3(0,0,0),vec3(180,0,90),
				    vec3(8));
    scene->addObject(objBuddha);

    Mesh * plan=new Mesh;
    plan->loadFromOBJFile("etc/plan.obj");
    plan->updateBBox();
    Material *matPlan=new Material(vec3(1),0,0);
    Object * objPlan = new Object(plan,matPlan,
    				  vec3(0,0,-0.7),vec3(0,0,0),
    				  vec3(5));
    scene->addObject(objPlan);

    Mesh * plan2=new Mesh;
    plan2->loadFromOBJFile("etc/plan.obj");
    plan2->updateBBox();
    Material *matPlan2=new Material(vec3(5),0,0);
    Object * objPlan2 = new Object(plan2,matPlan2,
				   vec3(0,0,1),vec3(0,0,0),
				  vec3(200));
    scene->addObject(objPlan2);


    LightPoint *light=new LightPoint(4,vec3(-2,0,-0.4),vec3(1,0.6,0.6),4.0);    
    LightPoint *light2=new LightPoint(4,vec3(-2,0,0.7),vec3(0.6,0.8,1),4.0);

    scene->addLightPoint(light);
    scene->addLightPoint(light2);

    WindowController controller(view,scene);
    controller.activate();   

    return 0;
}
