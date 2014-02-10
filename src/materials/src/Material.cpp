
/**
 * @file Material.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "Material.hpp"
#include <cmath>
using namespace std;
namespace materials
{

   Material::Material(const glm::vec3 & color):_properties()
   {
      _properties.setVectorProperty("color",color);
   }

   glm::vec3 Material::computeBRDF(const ray::Ray &shadowRay,
			 const glm::vec3 &normal)const
   {
      float coeff=fabs(glm::dot(shadowRay.getDirection(),normal));
      return _properties.getVectorProperty("color")*coeff;
   }

   void Material::displayTTY()const
   {
      cout<<"Material[";
      _properties.displayTTY();
      cout<<"]"<<endl;
   }


}
