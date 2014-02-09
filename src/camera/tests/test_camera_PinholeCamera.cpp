/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file test_camera_PinholeCamera.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include <iostream>
#include "utils_glm.hpp"
#include "Ray.hpp"
#include "PinholeCamera.hpp"
#include "Sphere.hpp"
#include "Intersection.hpp"

using namespace std;
using namespace camera;
using namespace glm;
using namespace ray;
using namespace scene;
int main()
{
   //PinholeCamera(position,target,up,nearPlan,farPlan,width,height,fov);
   PinholeCamera camera(vec3(-5,0,1),vec3(0,0,0),
		 vec3(0,1,0),0.001,1000.f,5,5,45.f);
   Ray ray=camera.generateRay(2,2);
   ray.displayTTY();
   Sphere sphere(vec3(0,0,0),1.0);
   sphere.displayTTY();
   Intersection inter;
   if(sphere.intersect(ray,inter))
   {
      cout<<"Intersection:"<<endl;
      inter.displayTTY();
   }
   else
   {
      cout<<"Pas d'intersection"<<endl;
   }
   return 0;
}
