/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Apr  6 2014
 * 
 */

/**
 * @file demo_depht_blur.cpp
 *  
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


#define WIDTH 400
#define HEIGHT 400

#define SPHERE_RADIUS 0.6


#define YMIN -3.3f
#define YMAX 3.3f
#define NB_COLUMNS 5

#define ZMIN -3.3f
#define ZMAX 3.3f
#define NB_ROWS 5


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
   utils::OpenglObject obj;
   
   sf::Image img;
   RaytracingEngine engine(&img,true,10);
   img.create(WIDTH,HEIGHT,sf::Color(0,0,20));

   gui::WindowView *view =new WindowView(WIDTH,HEIGHT,"Raytracer");

   camera::PinholeCamera *cam=
      new camera::PinholeCamera(vec3(-5,0,0),vec3(0,0,0),
				vec3(0,0,1),0.001,1000.f,WIDTH,
				HEIGHT,45.f,1);
   cam->setFocalPlan(5);
   
   scene::Scene * scene=new scene::Scene(cam);

   
   scene::Sphere *sphere1=new scene::Sphere(vec3(0),SPHERE_RADIUS);
   materials::Material *redDiffuse=
      new Material(vec3(1,0,0));
   scene::Object *redSphere=new Object(sphere1,redDiffuse,vec3(-1,1,1));
   scene->addObject(redSphere);

   scene::Sphere *sphere2=new scene::Sphere(vec3(0),SPHERE_RADIUS);
   materials::Material *greenDiffuse=
      new Material(vec3(0,1,0));
   scene::Object *greenSphere=new Object(sphere2,greenDiffuse,vec3(0,0,0));
   scene->addObject(greenSphere);
   
   scene::Sphere *sphere3=new scene::Sphere(vec3(0),SPHERE_RADIUS);
   materials::Material *blueDiffuse=
      new Material(vec3(0,0,1));
   scene::Object *blueSphere=new Object(sphere3,blueDiffuse,vec3(1,-1,-1));
   scene->addObject(blueSphere);

    addCheckerBackground(scene,3);

   
   LightPoint *light1=new LightPoint(15,vec3(-6,0,2),
				     vec3(1,1,1),1.0);   
   LightPoint *light2=new LightPoint(5,vec3(-6,0,-3),
				     vec3(1,1,1),1.0);  
   scene->addLightPoint(light1);
   scene->addLightPoint(light2);

   WindowController controller(view,scene);
   controller.activate();   

   return 0;
}
