/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Mon Feb 17 2014
 * 
 */

/**
 * @file test_scene_Vertex.cpp
 *  
 * Test of the class Vertex.
 */

#include "Vertex.hpp"

using namespace std;
using namespace glm;
using namespace scene;

int main()
{
   Vertex v1(vec3(0,1,0),vec3(1,1,0));
   cout<<"v1 ";
   v1.displayTTY();
   v1.setPosition(vec3(8,2,1));
   
   Vertex v2(v1);
   cout<<"v2 ";
   v2.displayTTY();
   v1.setNormal(vec3(-1,-2,-3));
   v2=v1;
   v2.displayTTY();
   cout<<"v1 ";
   cout<<v1.getPosition()<<" "<<v1.getNormal()<<endl;
   


   return 0;
}
