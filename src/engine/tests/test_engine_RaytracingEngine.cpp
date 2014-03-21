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
#include "WindowView.hpp"
#include "Mesh.hpp"
using namespace std;
using namespace glm;
using namespace scene;
using namespace camera;
using namespace engine;
using namespace materials;
using namespace light;
using namespace utils;
using namespace gui;

#include <cmath>


#define WIDTH 256
#define HEIGHT 256

#define PI 3.14159265



int main()
{
    
    sf::Image img;
    RaytracingEngine engine(&img);
    img.create(WIDTH,HEIGHT,sf::Color(0,0,20));
    PinholeCamera *cam=new PinholeCamera(vec3(-5,0,1),vec3(0,0,0),
					 vec3(0,1,0),5,1000.f,WIDTH,
					 HEIGHT,45.f);
    Sphere *sphere=new Sphere(vec3(0,0,0),0.5);
    Sphere *sphere2=new Sphere(vec3(0,1,0),0.5);
    Sphere *sphere3=new Sphere(vec3(0,-0.5,1),0.5);
    Sphere *sphere4=new Sphere(vec3(1,1,1),1.0);


    Material *red=new Material(vec3(1,1,0),0.2,0.7,2.4);
    Material *green=new Material(vec3(0,1,0),0.5,0.0,1.6);
    Material *blue=new Material(vec3(0,0,1),0.0,0.8,1.0);
    Material *white=new Material(vec3(1,1,1),0,0.0,1.0);
   

    Object *redSphere=new Object(sphere,red);
    Object * greenSphere=new Object(sphere2,green);
    Object * blueSphere=new Object(sphere3,blue);
    Object * whiteSphere=new Object(sphere4,white);

    LightPoint *light=new LightPoint(30,vec3(-6,-5,0),vec3(1,1,1),1.0);
    LightPoint *light2=new LightPoint(20,vec3(-6,2,0),vec3(1,1,1),1.0);
    Scene scene(cam);
    scene.addObject(redSphere);
    scene.addObject(greenSphere);
    scene.addObject(blueSphere);
    scene.addObject(whiteSphere);

    scene.addLightPoint(light);
    scene.addLightPoint(light2);
    engine.raytrace(scene);
    img.saveToFile("img.png");

   
    return 0;
}
