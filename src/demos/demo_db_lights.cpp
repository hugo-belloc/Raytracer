
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


#define WIDTH 400
#define HEIGHT 400



int main()
{
 
   gui::WindowView *view =new WindowView(WIDTH,HEIGHT,"Raytracer");

   camera::PinholeCamera *cam=
      new camera::PinholeCamera(vec3(-4,0,0),vec3(0,0,0),
				vec3(0,0,1),0.1,1000.f,WIDTH,
				HEIGHT,45.f);

   scene::Scene * scene=new scene::Scene(cam);

   scene::Sphere *sphere=new scene::Sphere(vec3(0),0.8);
   materials::Material *whiteDiffuse=
      new Material(vec3(1),0,0,0);
   scene::Object *sphereObj=new Object(sphere,whiteDiffuse,vec3(0),vec3(0,0,90));
   scene->addObject(sphereObj);


   LightPoint *light=new LightPoint(2.5,vec3(-2,0,1),vec3(1),2.0);   
   LightPoint *light2=new LightPoint(2,vec3(-2,0,-1),vec3(1),2.0);   
   scene->addLightPoint(light);
   scene->addLightPoint(light2);

   WindowController controller(view,scene);
   controller.activate();   

   return 0;
}
