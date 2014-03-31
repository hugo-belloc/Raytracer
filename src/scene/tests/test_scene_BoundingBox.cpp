/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Mar 30 2014
 * 
 */

/**
 * @file test_scene_BoundingBox.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include <iostream>
#include "Ray.hpp"
#include "BoundingBox.hpp"

using namespace std;
using namespace scene;
using namespace ray;
using namespace glm;

int main()
{
    BoundingBox bbox;
    bbox.surroundPoint(vec3(1,1,1));
    bbox.displayTTY();
    bbox.surroundPoint(vec3(-1,-1,-1));
    bbox.displayTTY();
    bbox.surroundPoint(vec3(2,0,-3));
    bbox.displayTTY();

    Ray ray(glm::vec3(-5,2.f,0.0f),
	    glm::vec3(1.2f,-0.3f,0.0f),0.f,1000.f,2);
    ray.displayTTY();
    cout<<boolalpha<<bbox.intersect(ray)<<endl;
    cout<<ray(5)<<endl;
   return 0;
}
