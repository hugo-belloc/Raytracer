
#include <iostream>
#include <string>
#include <sstream>

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

int main(int argc,char ** argv)
{
   if(argc!=2)
   {
      cout<<"Usage :"<<argv[0]<<" reflection"<<endl;
      return EXIT_FAILURE;
   }

   string strReflection(argv[1]);

   istringstream issReflection(strReflection);

   float reflection;
   issReflection>>reflection;
 
   gui::WindowView *view =new WindowView(WIDTH,HEIGHT,"Raytracer");

   camera::PinholeCamera *cam=
      new camera::PinholeCamera(vec3(-4,0,0),vec3(0,0,0),
				vec3(0,0,1),1,1000.f,WIDTH,
				HEIGHT,45.f);

   scene::Scene * scene=new scene::Scene(cam);

   addCheckerBackground(scene,-5.7);

   Mesh * ceiling=new Mesh;
   ceiling->loadFromOBJFile("etc/plan.obj");
   ceiling->updateBBox();
   Material *matCeiling=new Material(vec3(2),0,0);
   Object * objCeiling = new Object(ceiling,matCeiling,
   				    vec3(0,0,4),vec3(180,0,0),
   				    vec3(200));
   scene->addObject(objCeiling);


   scene::Sphere *sphere1=new scene::Sphere(vec3(0),0.8);
   materials::Material *redDiffuse=
      new Material(vec3(0.8,0.3,0.3),reflection);
   scene::Object *redSphere=new Object(sphere1,redDiffuse,vec3(0),vec3(0,0,90));
   scene->addObject(redSphere);

   LightPoint *light=new LightPoint(60,vec3(-5,0,2),vec3(1),2.0);
   
   scene->addLightPoint(light);

   WindowController controller(view,scene);
   controller.activate();   

   return 0;
}
