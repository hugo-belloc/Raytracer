
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
    glm::vec3 origin(1,0,0), direction(1,0,0);
    ray::Ray ray(origin,direction,0,100,5);
    ray.displayTTY();
    cout<<"min"<<ray.getTmin()<<" max"<<ray.getTmax()<<endl;
    glm::mat4 transfo= glm::mat4(1.f);
    
    transfo = glm::translate(transfo,glm::vec3(2,1,1));
    transfo=glm::rotate(transfo,90.f,glm::vec3(0,0,1));
    transfo = glm::scale(transfo,glm::vec3(2,1,1));

    ray.applyMatrix(transfo);
   
    ray.displayTTY();
    cout<<"min"<<ray.getTmin()<<" max"<<ray.getTmax()<<endl;

    return 0;
}
