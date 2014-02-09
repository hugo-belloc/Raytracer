
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file test_materials_MaterialsProperties.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#include "MaterialProperties.hpp"
using namespace std;
using namespace glm;

int main()
{
   materials::MaterialProperties prop;
   prop.setScalarProperty("ref",8.0);
   prop.setScalarProperty("trans",0.1);
   prop.setScalarProperty("ref",7.0);
   prop.setVectorProperty("color",vec3(1,0,0));
   prop.setVectorProperty("color",vec3(0,1,0));

   prop.displayTTY();
   cout<<endl;
   cout<<prop.hasScalarProperty("ref")<<prop.hasScalarProperty("bob")<<endl;
   cout<<prop.hasVectorProperty("color")<<prop.hasVectorProperty("vv")<<endl;

   return 0;
}
