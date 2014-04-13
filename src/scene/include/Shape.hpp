/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file Shape.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _SHAPE_HEADER_H
#define _SHAPE_HEADER_H


#include "utils_glm.hpp"
#include "Intersection.hpp"
#include "Ray.hpp"

namespace scene
{
    class Mesh;

    class Shape
    {
    public :
	/**
	 * Virtual destructor
	 */
	virtual ~Shape();

	/* Computes the intersection between a ray and the Shape
	 * in local space
	 * @param the ray to be intersected
	 * @param intersection the generated intersection 
	 * if there is one
	 * @return true if there is an intersection , false otherwise.
	 */
	virtual bool intersect(const ray::Ray & ray,Intersection & intersection)const=0;
	 /**
          * Displays the Shape (only for debug purpose.)
	  */
	virtual void displayTTY()const=0;
	//later for rasterisation purpose
      
	/**
	 * Construct a Mesh that if an approximation for the Shape
	 * @param resolution the resolution of the Mesh
	 */
	virtual void updateMesh(unsigned int resolution)=0;

	/**
	 * Return the lastest Mesh computed with the updateMesh
	 * method.
	 * @return a pointer to the Mesh
	 **/
	virtual const Mesh * getMesh() const=0;

    };
}

#endif
