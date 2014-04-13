
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


int main(int argc,char ** argv)
{
   if(argc!=3)
   {
      cout<<"Usage :"<<argv[0]<<" isBoxingEnable(0/1) size"<<endl;
      return EXIT_FAILURE;
   }

   string strIsBBoxEnable(argv[1]);
   string strSize(argv[2]);

   istringstream issIsBBoxEnable(strIsBBoxEnable);
   istringstream issSize(strSize);

   bool isBBoxEnable;
   float size;

   issIsBBoxEnable>>isBBoxEnable;
   issSize>>size;
 
   sf::Image img;
   utils::OpenglObject obj;
   RaytracingEngine engine(&img);
   img.create(WIDTH,HEIGHT,sf::Color(0,0,20));

   camera::PinholeCamera *cam=
      new camera::PinholeCamera(vec3(-5,0,0),vec3(0,0,0),
				vec3(0,0,1),0.001,1000.f,WIDTH,
				HEIGHT,45.f);
   
   scene::Scene * scene=new scene::Scene(cam);    

   Mesh * suzanne=new Mesh;
   suzanne->loadFromOBJFile("etc/cube.obj");
   cout<<suzanne->getVertexsNumber()<<" "<<suzanne->getFacesNumber();
   if(isBBoxEnable)
   {
      suzanne->updateBBox();
   }
   Material *matSuzanne=new Material(vec3(1),0,0);
   Object * objSuzanne = new Object(suzanne,matSuzanne,
				    vec3(0,0,0),vec3(180,0,90),
				    vec3(size));
   scene->addObject(objSuzanne);

   LightPoint *light=new LightPoint(30,vec3(-6,0,0),vec3(1,1,1),1);    
   scene->addLightPoint(light);

   engine.raytrace(*scene);
   img.saveToFile("save.png");
   delete scene;

   return 0;
}
