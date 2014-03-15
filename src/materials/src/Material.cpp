
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

    Material::Material(const glm::vec3 & color, 
		       float reflexion, 
		       float transmission, 
		       float mri):_properties()
    {
	_properties.setVectorProperty("color",color);
	_properties.setScalarProperty("reflexion",reflexion);
	_properties.setScalarProperty("transmission",transmission);
	_properties.setScalarProperty("mri",mri);
    }


    glm::vec3 Material::computeBRDF(const ray::Ray &shadowRay,
				    const glm::vec3 &normal)const
    {
	float coeff=fabs(glm::dot(shadowRay.getDirection(),normal));
	return _properties.getVectorProperty("color")*coeff;
    }

    float Material::getReflexionAttenuation()const
    {
	return _properties.getScalarProperty("reflexion");
    }

    float Material::getTransmissionAttenuation()const
    {
	return _properties.getScalarProperty("transmission");
    }

    float Material::getMRI()const
    {
	return _properties.getScalarProperty("mri");
    }

    /**
     * Change the amount of light reflected in the material
     * @param reflexion the new reflexion coefficient
     */
    void Material::setReflexionAttenuation(float reflexion)
    {
	_properties.setScalarProperty("reflexion",reflexion);
    }

    /**
     * Change the amount of light transmitted when a ray
     * hit the surface ie the opacity of the material
     * @param transmission the transparence of the material
     * a value to 0 means total opacity, 1 means total 
     * transparence.
     */
    void Material::setTransmissionAttenuation(float transmission)
    {
	_properties.setScalarProperty("reflexion",transmission);
    }

    /**
     * Change the MRI (material reflexion indice) of
     * the material
     * @param mri the new mri. Should be highter than 1.
     */
    void Material::setMRI(float mri)
    {
	_properties.setScalarProperty("mri",mri);
    }

    /**
     * Display the material value. This function is for
     * debug purpose only!
     */
    void Material::displayTTY()const
    {
	cout<<"Material[";
	_properties.displayTTY();
	cout<<"]"<<endl;
    }

    
    /**
     * Set the uniform ambient,diffuse and tranparency uniforms
     * in a given program.
     * @param prog the program to configure
     */
    void Material::setUniforms(const utils::Program & prog)const
    {
	prog.setUniform("ambient",
			glm::vec3(0,0,0));
	prog.setUniform("diffuse", 
			_properties.getVectorProperty("color"));
	float ref = getReflexionAttenuation();
	prog.setUniform("specular",
			glm::vec3(ref,ref,ref));
	prog.setUniform("shininess",
			100.f);
	float opacity = 1-_properties.getScalarProperty("transmission");
	prog.setUniform("opacity",opacity);	
    }

}
