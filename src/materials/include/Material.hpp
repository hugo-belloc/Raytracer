/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file Material.hpp
 *  
 * Declaration of the Material class.
 */


#ifndef _MATERIAL_HEADER_H
#define _MATERIAL_HEADER_H

#include <string>
#include <map>
#include "utils_glm.hpp"
#include "MaterialProperties.hpp"
#include "Ray.hpp"
#include "Program.hpp"

namespace materials
{
    class Material
    {
    public :
	Material(const glm::vec3 & color,
		 float reflexion=0.0,float transmission=0.0,
		 float mri=1.0);
	glm::vec3 computeBRDF(const ray::Ray &shadowRay,
			      const glm::vec3 & normal)const;

	float getReflexionAttenuation()const;
	void setReflexionAttenuation(float reflexion);

	float getTransmissionAttenuation()const;
	void setTransmissionAttenuation(float transmission);

	float getMRI()const;
	void setMRI(float mri);
       
	void displayTTY()const;
	void setUniforms(const utils::Program & prog)const;

    private :
	MaterialProperties _properties;
    };
}

#endif
