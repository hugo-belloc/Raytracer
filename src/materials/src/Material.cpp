
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
      _properties.setScalarProperty("reflexion",0.0);
      _properties.setScalarProperty("transmission",0.0);
   }

   Material::Material(const glm::vec3 & color, float reflexion, float transmission):_properties()
   {
      _properties.setVectorProperty("color",color);
      _properties.setScalarProperty("reflexion",reflexion);
      _properties.setScalarProperty("transmission",transmission);
   }


   glm::vec3 Material::computeBRDF(const ray::Ray &shadowRay,
			 const glm::vec3 &normal)const
   {
      float coeff=fabs(glm::dot(shadowRay.getDirection(),normal));
      return _properties.getVectorProperty("color")*coeff;
   }

   float Material::getReflexionAttenuation()
   {
      return _properties.getScalarProperty("reflexion");
   }

   float Material::getTransmissionAttenuation()
   {
      return _properties.getScalarProperty("transmission");
   }


   void Material::displayTTY()const
   {
      cout<<"Material[";
      _properties.displayTTY();
      cout<<"]"<<endl;
   }


}
