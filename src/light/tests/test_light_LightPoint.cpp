/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file test_light_LightPoint.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "LightPoint.hpp"

using namespace glm;
using namespace std;
using namespace light;
int main()
{
   LightPoint light(25,vec3(0,5,0),vec3(1,1,0),1);
   light.displayTTY();
   cout<<light.powerAt(vec3(0,0,0))<<endl;

   return 0;
}
