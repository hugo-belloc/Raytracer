/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Mon Feb 10 2014
 * 
 */

/**
 * @file test_engine_RaytracingEngine.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#include "RaytracingEngine.hpp"
#include "PinholeCamera.hpp"
#include "Sphere.hpp"
using namespace std;
using namespace glm;
using namespace scene;
using namespace camera;
using namespace engine;
using namespace materials;
using namespace light;

#define WIDTH 1000
#define HEIGHT 1000
int main()
{
   sf::Image img;
   RaytracingEngine engine(&img);
   img.create(WIDTH,HEIGHT,sf::Color(0,0,20));
   PinholeCamera *cam=new PinholeCamera(vec3(-5,0,1),vec3(0,0,0),
					vec3(0,1,0),0.001,1000.f,WIDTH,
					HEIGHT,45.f);
   Sphere *sphere=new Sphere(vec3(0,0,-1),0.6);
   Sphere *sphere2=new Sphere(vec3(0,0,0),0.4);
   Sphere *sphere3=new Sphere(vec3(1,1,0),0.6);

   Material *red=new Material(vec3(1,0,0),0.6,0);
   Material *green=new Material(vec3(0,1,0),0,0);
   Material *blue=new Material(vec3(0,0,1),0,0);
   

   Object *redSphere=new Object(sphere,red);
   Object * greenSphere=new Object(sphere2,green);
   Object * blueSphere=new Object(sphere3,blue);

   LightPoint *light=new LightPoint(30,vec3(-6,-5,0),vec3(1,1,1),1.0);
   LightPoint *light2=new LightPoint(20,vec3(-6,2,0),vec3(1,1,1),1.0);
   Scene scene(cam);
   scene.addObject(redSphere);
   scene.addObject(greenSphere);
   scene.addObject(blueSphere);

   scene.addLightPoint(light);
   scene.addLightPoint(light2);
   engine.raytrace(scene);
   img.saveToFile("img.png");
   
   return 0;
}
