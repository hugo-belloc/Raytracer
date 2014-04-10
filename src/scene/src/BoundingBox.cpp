/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Fri Mar 28 2014
 * 
 */

/**
 * @file BoundingBox.cpp
 *  
 */

#include <algorithm>
#include "BoundingBox.hpp"
#define EPSILON 1e-6f

using namespace std;

namespace scene
{
/**
 * Constructs a BoundingBox.
 * @param pMin the corner of the BoundingBox containing the
 * minimals values for x,y and z.
 * @param pMax the corner of the BoundingBox containing the
 * maximals values for x,y and z.
 */
    BoundingBox::BoundingBox(const glm::vec3 & pMin,
			     const glm::vec3 & pMax):
	BoundingShape(),_empty(false),_pMin(pMin),_pMax(pMax)
    {}

/**
 * This default constructor construct a BoundingBox. 
 * The bounding box cannot be used as it is and should 
 * be updated later whith the setPMin,setPMax and 
 * surroundPoint methods.
 */
    BoundingBox::BoundingBox():
	BoundingShape(),_empty(true),
	_pMin(glm::vec3(+INFINITY,+INFINITY,+INFINITY)),
	_pMax(glm::vec3(-INFINITY,-INFINITY,-INFINITY))
    {}

/**
 * Destructs a BoundingBox ...
 */
    BoundingBox::~BoundingBox()
    {}

/**
 * @return a vector containing the corner containing the 
 * minimals values of the Box.
 */
    glm::vec3 BoundingBox::getPMin() const
    {
	return _pMin;
    }

/**
 * @param the new value for the minimal corner of the Box.
 */
    void BoundingBox::setPmin(const glm::vec3 & pMin)
    {
	_pMin=pMin;
	_empty=false;
    }

/**
 * @return a vector containing the corner containing the 
 * maximals values of the Box.
 */
    glm::vec3 BoundingBox::getPMax() const
    {
	return _pMax;
    }

/**
 * @param the new value for the maximal corner of the Box.
 */
    void BoundingBox::setPmax(const glm::vec3 & pMax)
    {
	_pMax=pMax;
	_empty=false;

    }

/**
 * Extends (or not) the box to make it surround a given point.
 * @param the point to be surrounded by the box.
 */   
    void BoundingBox::surroundPoint(const glm::vec3 & point)
    {
	if(point.x<_pMin.x)
	{
	    _pMin.x=point.x;
	}
	if(point.x>_pMax.x)
	{
	    _pMax.x=point.x;
	}

	if(point.y<_pMin.y)
	{
	    _pMin.y=point.y;
	}
	if(point.y>_pMax.y)
	{
	    _pMax.y=point.y;
	}

	if(point.z<_pMin.z)
	{
	    _pMin.z=point.z;
	}
	if(point.z>_pMax.z)
	{
	    _pMax.z=point.z;
	}
	_empty=false;


    }


/**
 * Check if the bounding box intersect the ray.
 * An empty BoundingBox will always return false.
 *
 * @param ray the ray that may intersect the BoundingBox.
 * @return true if there is an intersection
 */
    bool BoundingBox::intersect(const ray::Ray & ray)const
    {
	if(getEmpty())
	{
	    return true;
	}

	const glm::vec3 & rDir = ray.getDirection();
	const glm::vec3 & rOrig = ray.getOrigin();
	glm::bvec3 positiveDir=glm::greaterThan(rDir,glm::vec3(0,0,0));    
	glm::vec3 invDir = glm::vec3(1/rDir.x,1/rDir.y,1/rDir.z);
	glm::vec3 t0,t1;
	float tMin=-INFINITY,tMax=INFINITY;
	const glm::vec3 * corners[2]={&_pMin,&_pMax};
	glm::bvec3 nullComponent = 
	    glm::lessThan(glm::abs(rDir),
			  glm::vec3(EPSILON,EPSILON,EPSILON));


	if(!nullComponent.x)
	{
	    t0.x = (corners[!positiveDir.x]->x - rOrig.x)*invDir.x;
	    t1.x = (corners[ positiveDir.x]->x - rOrig.x)*invDir.x;
	    if(t1.x < t0.x)
	    {
		return false;
	    }
	    tMin=t0.x;
	    tMax=t1.x;
	} 
	else
	{
	    if(rOrig.x<corners[0]->x || 
	       (rOrig.x>corners[1]->x))
	    {
		return false;
	    }
	}

	if(!nullComponent.y)
	{
	    t0.y = (corners[!positiveDir.y]->y - rOrig.y)*invDir.y;
	    t1.y = (corners[ positiveDir.y]->y - rOrig.y)*invDir.y;
    
	    if(t0.y>tMax || t1.y<tMin)
	    {
		return false;
	    }

	    tMin=std::max(tMin,t0.y);
	    tMax=std::min(tMax,t1.y);
	}
	else
	{
	    if(rOrig.y<corners[0]->y || 
	       (rOrig.y>corners[1]->y))
	    {
		return false;
	    }
	}

	if(!nullComponent.z)
	{
	    t0.z = (corners[!positiveDir.z]->z - rOrig.z)*invDir.z;
	    t1.z = (corners[ positiveDir.z]->z - rOrig.z)*invDir.z;
    
	    if(t0.z>tMax || t1.z<tMin)
	    {
		return false;
	    }

	    tMin=std::max(tMin,t0.z);
	    tMax=std::min(tMax,t1.z);
	}
	else
	{
	    if(rOrig.z<corners[0]->z || 
	       (rOrig.z>corners[1]->z))
	    {
		return false;
	    }
	}

	if(tMax<ray.getTmin()||tMax>ray.getTmax())
	{
	    return false;
	}

	return true;    
    }

    
    /**
     * Indicate whether the bounding box is empty or
     * not.
     * @return true if the bounding box is empty, false otherwise.
     */
    bool BoundingBox::getEmpty()const
    {
	return _empty;
    }

    /**
     * Displays the content of the Bounding Box.
     * For debug purpose only.
     */
    void BoundingBox::displayTTY()
    {
	std::cout<<"Bounding Box[Min corner="<<_pMin;
	std::cout<<", Max corner="<<_pMax<<"]"<<std::endl;	
    }


}
