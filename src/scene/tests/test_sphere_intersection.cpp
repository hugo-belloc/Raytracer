/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sat Feb  8 2014
 * 
 */

#include <iostream>
#include "Ray.hpp"
#include "Intersection.hpp"
#include "Sphere.hpp"


using namespace std;
using namespace glm;
using namespace ray;
using namespace scene;

int main()
{
   Sphere sphere(vec3(-3,0,0),2);
   Ray ray(vec3(10,1,1),vec3(-1,0,0),100,0);
   sphere.displayTTY();
   ray.displayTTY();
   Intersection inter;
   if(sphere.intersect(ray,inter))
   {
      inter.displayTTY();
   }
   else
   {
      cout<<"Pas d'intersection"<<endl;
   }
   
   return 0;
}
