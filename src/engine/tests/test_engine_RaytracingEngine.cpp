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

#define WIDTH 500
#define HEIGHT 500
int main()
{
   sf::Image img;
   RaytracingEngine engine(&img);
   img.create(WIDTH,HEIGHT,sf::Color(0,0,20));
   PinholeCamera *cam=new PinholeCamera(vec3(-5,0,1),vec3(0,0,0),
					vec3(0,1,0),0.001,1000.f,WIDTH,
					HEIGHT,45.f);
   Sphere *sphere=new Sphere(vec3(0,0,0),1.0);
   Material *mat=new Material(vec3(1,0,0));
   Object *objSphere=new Object(sphere,mat);
   LightPoint *light=new LightPoint(20,vec3(-6,0,0),vec3(1,1,1),1.0);
   Scene scene(cam);
   scene.addObject(objSphere);
   scene.addLightPoint(light);
   
   engine.raytrace(scene);
   img.saveToFile("img.png");
   
   return 0;
}
