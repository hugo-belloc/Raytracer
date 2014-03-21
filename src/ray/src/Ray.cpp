
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sat Feb  8 2014
 * 
 */

/**
 * @file Ray.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */
#include "Ray.hpp"

using namespace std;



namespace ray
{

/**
 * Constructs a ray.
 *
 * @param origin the point the ray originate from
 * @param direction a vector representing the direction
 * of the ray
 * @param type the type of ray = ShadowRay or CameraRay
 * @param tmax the maximum value during parametrisation
 * @param tmax the minimum value during parametrisation
 */
    Ray::Ray(const glm::vec3 & origin ,const glm::vec3 & direction,float tmin, float tmax, int bounces,int mri):
	_origin(origin),_direction(glm::normalize(direction)), _tmin(tmin),_tmax(tmax),_bounces(bounces),_mri(mri)
    {}

/**
 * Virtual destructor
 */
    Ray::~Ray()
    {}
   
/**
 * Compute on point coordinate along the ray.
 * by origin+t*direction
 *
 * @param the parameter t of the formula
 * @return the computed coordinate
 */
    glm::vec3 Ray::operator()(float t) const
    {
	return _origin+_direction*t;
    }
   
    Ray & Ray::operator=(const Ray & ray)
    {
	_origin=ray._origin;
	_direction=ray._direction;
	_tmax=ray._tmax;
	_tmin=ray._tmin;
	_bounces=ray._bounces;

	return *this;
    }


/**
 * Return the nomber of bounces left. When it
 * reach 0 the ray should not be launch
 */
    int Ray::getBounces() const
    {
	return _bounces;
    }
    void Ray::setBounces(int bounces)
    {
	_bounces = bounces;
    }


    void Ray::setTmax(float newTmax)const 
    {
	_tmax=newTmax;
    }

    void Ray::setTmin(float newTmin)const 
    {
	_tmin=newTmin;
    }

    float Ray::getTmax() const
    {
	return _tmax;
    }
   
    float Ray::getTmin() const
    {
	return _tmin;
    }   
   
    void Ray::displayTTY()const
    {
	std::cout<<"Ray[origin="<<_origin;
	std::cout<<",direction="<<_direction<<"]"<<std::endl;
    }
    glm::vec3 Ray::getOrigin()const
    {
	return _origin;
    }

    void Ray::setOrigin(const glm::vec3 & origin)
    {
	_origin = origin;
    }

    glm::vec3 Ray::getDirection()const
    {
	return _direction;
    }

    void Ray::setDirection(const glm::vec3 & direction)
    {
	_direction=direction;
    }

    float Ray::getMRI() const
    {
	return _mri;
    }

    glm::vec3 Ray::getColor() const
    {
	glm::vec3 color(0,0,0);
	return color;
    }

    /**
     * Generate the same ray in a different coordonate
     * system. 
     * @param transformationMatrix the transformation matrix
     * of the new sytem. 
     */
    void Ray::applyMatrix(const glm::mat4 & transformationMatrix ) 
    {
	glm::vec4 dirH  = glm::vec4(getDirection(),0);
	dirH = transformationMatrix * dirH;
	glm::vec4 origH = glm::vec4(getOrigin(),1);
	origH =  transformationMatrix * origH;
	
	_direction = dirH.xyz;
	_origin = origH.xyz;

	float norm = glm::l2Norm(_direction);
	_tmin*=norm;
	_tmax*=norm;
	_direction *=(1/norm);	
    }

}

