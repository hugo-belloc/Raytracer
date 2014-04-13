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


#define WIDTH 512
#define HEIGHT 512

#define SPHERE_RADIUS 0.6
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
				HEIGHT,45.f,0.3);
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
