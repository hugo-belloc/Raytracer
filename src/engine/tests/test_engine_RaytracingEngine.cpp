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
#include <cmath>

#define WIDTH 1024
#define HEIGHT 1024
#define NUMBER_SPHERES 8
#define X_SPHERES -0.5
#define PI 3.14159265

int main()
{
    sf::Image img;
    RaytracingEngine engine(&img);
    img.create(WIDTH,HEIGHT,sf::Color(0,0,0));
    PinholeCamera *cam=new PinholeCamera(vec3(-5,0,0),vec3(0,0,0),
					 vec3(0,1,0),0.001,1000.f,WIDTH,
					 HEIGHT,45.f);
   
    Scene scene(cam);

    for(int i=0;i<NUMBER_SPHERES;++i)
    {
	float angle=(2*PI*i)/NUMBER_SPHERES;
	Sphere *sphere=new Sphere(vec3(X_SPHERES,cos(angle),
				       sin(angle)),0.35);
	Material *material=new Material(vec3(0,
					     fabs(cos(angle/2)),
					     fabs(sin(angle/2))));
        Object *object=new Object(sphere,material);
	scene.addObject(object);
    }
   
    LightPoint *light=new LightPoint(40,vec3(-6,-5,0),vec3(1,1,1),1.0);
    
    LightPoint *light2=new LightPoint(20,vec3(-6,5,0),vec3(1,1,1),1.5);

    scene.addLightPoint(light);
    scene.addLightPoint(light2);
    engine.raytrace(scene);
    img.saveToFile("img.png");
   
    return 0;
}
