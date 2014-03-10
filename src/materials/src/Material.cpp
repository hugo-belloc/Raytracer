
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
	_properties.setVectorProperty("ambient",glm::vec3(0,0,0));
	_properties.setVectorProperty("diffuse",color);
	_properties.setVectorProperty("specular",glm::vec3(1,1,1));
	_properties.setScalarProperty("shininess",100.0f);
	_properties.setScalarProperty("opacity",1.0);	
	
    }

    glm::vec3 Material::computeBRDF(const ray::Ray &shadowRay,
				    const glm::vec3 &normal)const
    {
	float coeff=fabs(glm::dot(shadowRay.getDirection(),normal));
	return _properties.getVectorProperty("diffuse")*coeff;
    }

    void Material::displayTTY()const
    {
	cout<<"Material[";
	_properties.displayTTY();
	cout<<"]"<<endl;
    }

    
    /**
     * Set the uniform ambient,diffuse and tranparency uniforms
     * in a given program.
     */
    void Material::setMaterialUniforms(utils::Program & prog)const
    {
	prog.setUniform("ambient",
			_properties.getVectorProperty("ambient"));
	prog.setUniform("diffuse", 
			_properties.getVectorProperty("diffuse"));
	prog.setUniform("specular",
			_properties.getVectorProperty("specular"));
	prog.setUniform("shininess",
			_properties.getScalarProperty("shininess"));
	prog.setUniform("opacity",
			_properties.getScalarProperty("opacity"));	
    }

}
