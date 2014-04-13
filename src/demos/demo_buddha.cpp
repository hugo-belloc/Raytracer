

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


#define WIDTH 200
#define HEIGHT 200


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

   

    Mesh * ceiling=new Mesh;
    ceiling->loadFromOBJFile("etc/plan.obj");
    ceiling->updateBBox();
    Material *matCeiling=new Material(vec3(1),0,0);
    Object * objCeiling = new Object(ceiling,matCeiling,
				   vec3(0,0,2),vec3(180,0,0),
				  vec3(200));
    scene->addObject(objCeiling);

     Mesh * ground=new Mesh;
    ground->loadFromOBJFile("etc/plan.obj");
    ground->updateBBox();
    Material *matGround=new Material(vec3(1),0,0);
    Object * objGround = new Object(ground,matGround,
				   vec3(0,0,-0.6),vec3(0,0,0),
				  vec3(200));
    scene->addObject(objGround);


    LightPoint *light=new LightPoint(0.4,vec3(-1,0,0.5),vec3(1),0.4);    
    LightPoint *light2=new LightPoint(1,vec3(-5,0,0),vec3(1),0.4);

    scene->addLightPoint(light);
    scene->addLightPoint(light2);

    WindowController controller(view,scene);
    controller.activate();   

    return 0;
}
