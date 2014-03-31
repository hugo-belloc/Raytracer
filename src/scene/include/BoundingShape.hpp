/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Fri Mar 28 2014
 * 
 */

/**
 * @file BoundingShape.hpp
 *  
 */


#ifndef _BOUNDINGSHAPE_HEADER_H
#define _BOUNDINGSHAPE_HEADER_H

#include "Ray.hpp"

namespace scene
{
    /**
     * An abstract class using to "surrounds" the
     * Shape in order to speed the render.
     */

    class BoundingShape
    {
    public :
	BoundingShape();
	virtual ~BoundingShape();

	/**
	 * Computes the intersection between the ray and
	 * the box.
	 * @return true if there is an intersection, else
	 * otherwise.
	 */
	virtual bool intersect(const ray::Ray & ray)const=0;

    };
}
#endif
