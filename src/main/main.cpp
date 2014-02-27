/**
 * @file main.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include <iostream>
#include "WindowView.hpp"
#include "RaytracingContent.hpp"
#include "TriangleContent.hpp"
#include "PinholeCamera.hpp"
#include "Sphere.hpp"

using namespace std;


#define WIDTH 500
#define HEIGHT 500

// scene::Scene initScene()
// {
//    PinholeCamera *cam=new PinholeCamera(vec3(-5,0,1),vec3(0,0,0),
// 					vec3(0,1,0),0.001,1000.f,WIDTH,
// 					HEIGHT,45.f);
//    Sphere *sphere=new Sphere(vec3(0,0,0),1.0);
//    Sphere *sphere2=new Sphere(vec3(2,1,0),2.3);
//    Material *red=new Material(vec3(1,0,0));
//    Material *green=new Material(vec3(0,1,0));
   
//    Object *redSphere=new Object(sphere,red);
//    Object * greenSphere=new Object(sphere2,green);
//    LightPoint *light=new LightPoint(30,vec3(-6,-5,0),vec3(1,1,1),1.0);
//    LightPoint *light2=new LightPoint(20,vec3(-6,2,0),vec3(1,1,1),1.0);
//    Scene scene(cam);
//    scene.addObject(redSphere);
//    scene.addObject(greenSphere);
//    scene.addLightPoint(light);
//    scene.addLightPoint(light2);

//    return scene;
// }

int main()
{
   gui::WindowView view(512,512);
   gui::WindowModel * model=view.getModel();
   // Scene scene= initScene();
   model->addContent(new gui::TriangleContent);
   view.beginMainLoop();
   return 0;
}
