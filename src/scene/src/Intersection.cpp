/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sat Feb  8 2014
 * 
 */

/**
 * @file Intersection.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "Intersection.hpp"

using namespace std;

namespace scene
{
    Intersection::Intersection():
	_hitPoint(glm::vec3(0,0,0)),
	_normal(glm::vec3(0,0,0)),_material(0)
    {}

    Intersection::Intersection(const glm::vec3 & hitPoint,
			       const glm::vec3 & normal,
			       materials::Material * material) :
	_hitPoint(hitPoint),_normal(glm::normalize(normal)),
	_material(material)
    {}

    glm::vec3 Intersection::getPoint()const
    {
	return _hitPoint;
    }

    glm::vec3 Intersection::getNormal()const
    {
	return _normal;
    }

    void Intersection::setPoint(const glm::vec3 & point)
    {
	_hitPoint=point;
    }

    void Intersection::setNormal(const glm::vec3 & normal)
    {
	_normal=glm::normalize(normal);
    }

    materials::Material * Intersection::getMaterial()const
    {
	return _material;
    }

    void Intersection::setMaterial(materials::Material * mat)
    {
	_material=mat;
    }

    Intersection & Intersection::operator=(const Intersection & intersection)
    {
	_hitPoint=intersection._hitPoint;
	_normal=intersection._normal;
	_material=intersection._material;
	return *this;
    }

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
