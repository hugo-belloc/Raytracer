/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sat Feb  8 2014
 * 
 */


#include "Intersection.hpp"

using namespace std;

namespace scene
{
    /**
     * Constructs an empty intersection with default value.
     * Those value should be changed later.
     */
    Intersection::Intersection():
	_hitPoint(glm::vec3(0,0,0)),
	_normal(glm::vec3(0,0,0)),_material(0)
    {}

    /**
     * Create an intersection.
     * @param hitPoint the point where the intersection happens.
     * @param normal the normal to the surface hit.
     * @param material a pointer to the material of the surface
     */
    Intersection::Intersection(const glm::vec3 & hitPoint,
			       const glm::vec3 & normal,
			       materials::Material * material) :
	_hitPoint(hitPoint),_normal(glm::normalize(normal)),
	_material(material)
    {}

    /**
     * @return the origin of the intersection
     */
    glm::vec3 Intersection::getPoint()const
    {
	return _hitPoint;
    }

    /**
     * @return the normal to the surface intersected
     */
    glm::vec3 Intersection::getNormal()const
    {
	return _normal;
    }

    /**
     * Change the origin of the intersection
     * @param the new origin ie the point of the
     * surface hit by the ray.
     */
    void Intersection::setPoint(const glm::vec3 & point)
    {
	_hitPoint=point;
    }

    /**
     * Change the normal to the surface intersected
     * @param the new normal.
     */
    void Intersection::setNormal(const glm::vec3 & normal)
    {
	_normal=glm::normalize(normal);
    }

    /**
     * @return a pointer over the material of the intersected surface.
     */
    materials::Material * Intersection::getMaterial()const
    {
	return _material;
    }

    /**
     * Change the material of the surface intersected
     * @param the new material.
     */
    void Intersection::setMaterial(materials::Material * mat)
    {
	_material=mat;
    }

    /**
     * Make the current intersectino a copy of another intersection.
     * @param the intersection we should copy. 
     */
    Intersection & Intersection::operator=(const Intersection & intersection)
    {
	_hitPoint=intersection._hitPoint;
	_normal=intersection._normal;
	_material=intersection._material;
	return *this;
    }

    /**
     * Displays the intersection, only for debug purpose.
     */
    void Intersection::displayTTY()
    {
	cout<<"Intersection"<<"[Point="<<_hitPoint;
	cout<<",Normal="<<_normal<<"]"<<endl;
	if(_material)
	{
	    _material->displayTTY();
	}
    }

    /**
     * Change the coordonnates system of the interesection
     * tranfMat3
     * @param transformationMatrix the matrix of the
     * new coordonates system.
     * @param normalMatrix the matrix to apply to the normal
     * normally transpose(inverse(transformationMatrix)).
     */
    void Intersection::applyMatrix(const glm::mat4 & transformationMatrix,
				   const glm::mat3 & normalMatrix)
    {
	glm::vec4 pointH=glm::vec4(getPoint(),1);
	pointH=transformationMatrix*pointH;
	setPoint(pointH.xyz*(1/pointH.w));
	glm::vec3 normal = getNormal();
	setNormal(normalMatrix*normal);
    }
    
    /**
     * Change the coordonnates system of the interesection
     * tranfMat3
     * @param transformationMatrix the matrix of the
     * new coordonates system.
     */
    void Intersection::applyMatrix(const glm::mat4 & transformationMatrix)
    {
	glm::vec4 pointH=glm::vec4(getPoint(),1);
	pointH=transformationMatrix*pointH;
	setPoint(pointH.xyz*(1/pointH.w));
	glm::mat3 normalMatrix=glm::mat3(transformationMatrix);
	normalMatrix=glm::transpose(glm::inverse(normalMatrix));
	glm::vec3 normal = getNormal();
	setNormal(normalMatrix*normal);	
    }

}
