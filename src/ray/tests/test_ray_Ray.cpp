
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sat Feb  8 2014
 * 
 */

/**
 * @file test_ray_Ray.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "utils_glm.hpp"
#include "Ray.hpp"

using namespace std;

int main()
{
   glm::vec3 origin(1,0,0), direction(1,1,0);
   ray::Ray ray(origin,direction,ray::CameraRay,100,0);
   ray.display();
   cout<<ray(1.0)<<endl<<ray(1.5)<<endl;
   return 0;
}
