/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file Object.cpp
 *  
 * Definition of the Object class.
 */

#include "Object.hpp"
#include "Mesh.hpp"
using namespace std;

namespace scene
{

    unsigned int Object::defaultResolution=20;

    /**
     * Create an Object from a shape a material and
     * some transformation properties.
     * @param shape : the Shape to be displayed.
     * the Shape is specific to an object.
     * @param material : the Material of the
     * object.
     * @param location : the location of the center
     * of the mesh in the world coordinate. (Translate
     * the mesh)
     * @param rotation : gives a rotate the object.
     * the object will first be rotated along the
     * world x axis, then along the world y axis
     * and then along the world z axis.
     * @param scale : scales the object in it local 
     * space.
     */
    Object::Object(scene::Shape * shape,
		   materials::Material * material,
		   const glm::vec3 & location,
		   const glm::vec3 & rotation,
		   const glm::vec3 & scale):
	_shape(shape),_material(material),_location(location),
	_rotation(rotation),_scale(scale)
    {
	_shape->updateMesh(defaultResolution);
	updateMatrices();
    }

    /**
     * Destroy the object with it shape
     * and it material.
     */
    Object::~Object()
    {
	delete _shape;
	delete _material;
    }

    /**
     * Checks and compute the intersection between a ray
     * and an object.
     * @param ray : the ray to be intersected.
     * @param intersection : if the ray and the
     * object intersect contains the intersection.
     * @return true if the object intersects the ray
     * false otherwise.
     */
    bool Object::intersect(const ray::Ray & ray,
			   Intersection & intersection)const
    {
	
	ray::Ray rayLocal=ray;

	//Translate matrix to local space and compute inter in this space
	rayLocal.applyMatrix(_inverseModelMatrix);
	bool isIntersected= _shape->intersect(rayLocal,intersection);
	if(isIntersected)
	{
	    intersection.setMaterial(getMaterial());
	    //Return in world space
	    intersection.applyMatrix(_modelMatrix,_normalMatrix);
	}
	return isIntersected;
    }

    /**
     * @return the material of the
     * object.
     */
    materials::Material * Object::getMaterial()const
    {
	return _material;
    }

    /**
     * @return the location of the center
     * of the Mesh in the world coordinates.
     */
    glm::vec3 Object::getLocation() const
    {
	return _location;
    }

    /**
     * @return the rotations of the object
     * of the Mesh in the world coordinates.
     */
    glm::vec3 Object::getRotation() const
    {
	return _rotation;
    }

    /**
     * @return the scale of the object
     * with the local coordinates.
     */ 
    glm::vec3 Object::getScale() const
    {
	return _scale;
    }

    /**
     * Change the location of the object
     * @param 
     */
    void Object::setLocation(const glm::vec3 & location)
    {
	_location=location;
	updateMatrices();
    }

    /**
     * Change the rotation of the object
     * @param rotation the new rotation
     * of the object.
     */
    void Object::setRotation(const glm::vec3 & rotation)
    {
	_rotation=rotation;
	updateMatrices();
    }

    /**
     * Change the scale of the object.
     * @param scale the new scale of the 
     * object.
     */
    void Object::setScale(const glm::vec3 & scale)
    {
	_scale=scale;
	updateMatrices();
    }

    /**
     * @return the model matrix.
     */
    glm::mat4 Object::getModelMatrix()const
    {
	return _modelMatrix;
    }

    /**
     * @return the inverse of the model Matrix
     */
    glm::mat4 Object::getInverseModelMatrix()const
    {
	return _inverseModelMatrix;
    }

    /**
     * @return the inverse of the normal
     * matrix ie the transpose of the inverse
     * of the model matrix
     */
    glm::mat3 Object::getNormalMatrix()const
    {
	return _normalMatrix;
    }
        

    /**
     * Update the object representation.
     * this method is to be used if the Shape
     * in the mesh has changed or to change the
     * resolution .
     *
     * @resolution the resolution used to draw the object.
     */
    void Object::updateMesh(unsigned int resolution)
    {
	_shape->updateMesh(resolution);
    }

    /**
     * Update the object representation.
     * with the default definition.
     *
     * @sa updateMesh(unsigned int)
     */
    void Object::updateMesh()
    {
	updateMesh(defaultResolution);
    }
    /**
     * Sets the Object uniforms.
     * @param prog
     */
    void Object::setUniforms(const utils::Program & prog)const
    {
	_material->setUniforms(prog);
    }

    /**
     * Draw the Shape contained within the Object.
     */
    void Object::draw()const
    {
	_shape->getMesh()->draw();
    }

    /**
     * Diplay the content of the object in the standart 
     * output. For debug purpose.
     */
    void Object::diplayTTY()const
    {
	cout<<"Object"<<endl<<"["<<endl;
	cout<<"   ";
	_shape->displayTTY();
	cout<<"   ";
	_material->displayTTY();
	cout<<"   location: "<<_location<<endl;
	cout<<"   rotation: "<<_rotation<<endl;
	cout<<"   scale: "<<_scale<<endl;
	cout<<"]"<<endl<<endl;
    }

    
    void  Object::updateMatrices()
    {
	_modelMatrix = glm::translate(_modelMatrix,_location);
	
	_modelMatrix = glm::rotate(_modelMatrix,_rotation.x,
				   glm::vec3(1,0,0));
	_modelMatrix = glm::rotate(_modelMatrix,_rotation.y,
				   glm::vec3(0,1,0));
	_modelMatrix = glm::rotate(_modelMatrix,_rotation.z,
				   glm::vec3(0,0,1));
	_modelMatrix = glm::scale(_modelMatrix,_scale);
	_inverseModelMatrix = glm::inverse(_modelMatrix);
	_normalMatrix=glm::mat3(glm::transpose(_inverseModelMatrix));
    }

}
