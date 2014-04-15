
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

#define YMIN -3.3f
#define YMAX 3.3f
#define NB_COLUMNS 5

#define ZMIN -3.3f
#define ZMAX 3.3f
#define NB_ROWS 5


void addCheckerBackground(Scene * scene,float x)
{
   vec3 black(0);
   vec3 white(1);
   float stepY = (YMAX-YMIN)/(float)NB_COLUMNS;
   float stepZ = (ZMAX-ZMIN)/(float)NB_COLUMNS;
   
   for(int i=0;i<NB_COLUMNS;++i)
   {
      for(int j=0;j<NB_COLUMNS;++j)
      {
	 
	 Mesh * plan=new Mesh;
	 plan->loadFromOBJFile("etc/plan.obj");
	 plan->updateBBox();
 
	 Material *matPlan=new Material(((i+j)%2)?white:black,0,0);
	 Object * objPlan = new Object(plan,matPlan,
				       vec3(x,YMIN+(i+0.5)*stepY,
					    ZMIN+(j+0.5)*stepZ),
				       vec3(0,(x>0)?-90:90,0), vec3(stepY*0.5,stepZ*0.5,1));
	 scene->addObject(objPlan);
      }
   }
}

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
    Material *matSuzanne=new Material(vec3(1,0.4,0.2),0,0);
    Object * objSuzanne = new Object(suzanne,matSuzanne,
				    vec3(0,0,0),vec3(180,-30,90),
				    vec3(0.8));
    scene->addObject(objSuzanne);



   addCheckerBackground(scene,3);


   
   LightPoint *light=new LightPoint(60,vec3(-5,0,2),vec3(1),2.0);
   
   scene->addLightPoint(light);



    WindowController controller(view,scene);
    controller.activate();   

    return 0;
}
