
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Fri Mar 21 2014
 * 
 */



#include "RaytracingEngine.hpp"
#include "PinholeCamera.hpp"
#include "Sphere.hpp"
#include "WindowView.hpp"
#include "Mesh.hpp"
#include "RasterisationContent.hpp"
#include "RaytracingContent.hpp"

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



#define WIDTH 512
#define HEIGHT 512


#define PI 3.14159265



int main()
{

    utils::OpenglObject obj;
   
    sf::Image img;
    RaytracingEngine engine(&img,true,10);
    img.create(WIDTH,HEIGHT,sf::Color(0,0,20));
    PinholeCamera *cam=new PinholeCamera(vec3(-5,0,0),vec3(0,0,0),
					 vec3(0,1,0),0.001,1000.f,WIDTH,
					 HEIGHT,45.f,0.02);
    Sphere *sphere =new Sphere(vec3(0,0,0),0.3);
    Sphere *sphere2=new Sphere(vec3(2,0,0),2);
    Sphere *sphere3=new Sphere(vec3(3,0,0),5);
    Sphere *sphere4=new Sphere(vec3(10,0,0),10);

    Material *red=new Material(vec3(1,0,0));
    Material *green=new Material(vec3(0,1,0));
    Material *blue=new Material(vec3(0,0,1));   
    Material *white=new Material(vec3(1,1,1));   


    Object *redSphere=new Object(sphere,red,vec3(0,0,0));
    Object * greenSphere=new Object(sphere2,green,vec3(2,0,0));
    Object * blueSphere=new Object(sphere3,blue,vec3(8,0,0));
    Object * whiteSphere=new Object(sphere4,white,vec3(8,0,0));

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
