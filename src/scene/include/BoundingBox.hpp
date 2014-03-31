/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Fri Mar 28 2014
 * 
 */

/**
 * @file BoundingBox.hpp
 *  
 */


#ifndef _BOUNDINGBOX_HEADER_H
#define _BOUNDINGBOX_HEADER_H

#include "BoundingShape.hpp"

namespace scene
{
/**
 * A Box containing the shape of the object.
 * Allow to compute fast intersection to
 * gains some speed on the render.
 */
    class BoundingBox : public BoundingShape
    {
    public :
	BoundingBox(const glm::vec3 & pMin,
		    const glm::vec3 & pMax);
	BoundingBox();
	virtual ~BoundingBox();
   
	glm::vec3 getPMin() const;
	void setPmin(const glm::vec3 & pMin);
	glm::vec3 getPMax() const;
	void setPmax(const glm::vec3 & pMax);
   
	void surroundPoint(const glm::vec3 & point);
	virtual bool intersect(const ray::Ray & ray)const;
	void displayTTY();
   

    private :
	glm::vec3 _pMin;
	glm::vec3 _pMax; 
       

    };
}
#endif
