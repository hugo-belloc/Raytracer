
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file Object.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _OBJECT_HEADER_H
#define _OBJECT_HEADER_H

#include "utils_glm.hpp"
#include "Ray.hpp"
#include "Material.hpp"
#include "Shape.hpp"

namespace scene
{
    /**
     * An Object is a Shape to be displayed, a Material
     * to configure it visual aspect, and some transformation
     * properties (location,rotation,scale).
     */
    class Object
    {
    public :
	/**
	 * The default resolution used to converts
	 * the Shapes in the object into Meshs.
	 * Default is 20.
	 */
	static unsigned int defaultResolution;

	Object(scene::Shape * shape,
	       materials::Material * material,
	       const glm::vec3 & location=glm::vec3(0,0,0),
	       const glm::vec3 & rotation=glm::vec3(0,0,0),
	       const glm::vec3 & scale=glm::vec3(1,1,1));
	~Object();
	bool intersect(const ray::Ray & ray,
		       Intersection & intersection)const;
	materials::Material * getMaterial()const;      

	glm::vec3 getLocation() const;
	glm::vec3 getRotation() const;
	glm::vec3 getScale() const;
	void setLocation(const glm::vec3 & location);
	void setRotation(const glm::vec3 & rotation);
	void setScale(const glm::vec3 & scale);
	
	glm::mat4 getModelMatrix()const;
	glm::mat4 getInverseModelMatrix()const;
	glm::mat3 getNormalMatrix()const;
	
	void updateMesh(unsigned int resolution);
	void updateMesh();

	void setUniforms(const utils::Program & prog) const;
	void draw()const;

	void diplayTTY()const;
	

    private :
	void updateMatrices();
	scene::Shape * _shape;
	materials::Material * _material;
	glm::vec3 _location;
	glm::vec3 _rotation;
	glm::vec3 _scale;
	glm::mat4 _modelMatrix;
	glm::mat4 _inverseModelMatrix;
	glm::mat3 _normalMatrix;
    };
}
#endif
