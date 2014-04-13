
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sat Feb  8 2014
 * 
 */

/**
 * @file Sphere.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "Quadratic.hpp"
#include "Sphere.hpp"


using namespace std;

namespace scene
{

    /**
     * Constructs a Sphere
     * @param center describe the center of the sphere
     * in local coordinate.
     * @param radius the radius of the sphere created
     */
    Sphere::Sphere(const glm::vec3 &center,float radius):/*Shape(),*/_center(center),_radius(radius),_mesh(new Mesh)
    {}

    /**
     * Destroy the sphere by desallocating the 
     * memory.
     */
    Sphere::~Sphere()
    {
	delete _mesh;
    }

    /**
     * Change the center of the sphere
     * @param center the new center of the sphere.
     */
    void  Sphere::setCenter(const glm::vec3 &center)
    {
	_center=center;
    }

    /**
     * @return The center of the sphere (in local coordinate)
     *
     */
    glm::vec3  Sphere::getCenter()const
    {
	return _center;
    }

    /**
     * @return the radius of the sphere
     */
    float  Sphere::getRadius()const 
    {
	return _radius;
    }

    /**
     * Change the radius of the sphere.
     * @param radius the new radius
     */
    void  Sphere::setRadius(float radius)
    {
	_radius=radius;
    }

    /**
     * Computes the intersection between a ray and the sphere
     * in local space
     * @param the ray to be intersected
     * @param intersection the generated intersection 
     * if there is one
     * @return true if there is an intersection , false otherwise.
     */
    bool Sphere::intersect(const ray::Ray & ray,
			   Intersection & intersection)const 
    {
	glm::vec3 dir=ray.getDirection();
	glm::vec3 oriToCenter=ray.getOrigin()-_center;
	float a=glm::dot(dir,dir);
	float b=2*glm::dot(dir,oriToCenter);
	float c=glm::dot(oriToCenter,oriToCenter)-_radius*_radius;
	math::Quadratic equation(a,b,c);
	float tInterMin,tInterMax;
	bool isIntersection=equation.solve(tInterMin,tInterMax);
	
	if(isIntersection)
	{
	    //if the first solution is not between tmin and tmax
	    //we take the other one
	    float tSol=tInterMin;
	    if(tSol<ray.getTmin() || tSol>ray.getTmax())
	    {
		tSol=tInterMax;
	    }

	    isIntersection = isIntersection &&
		tSol>=ray.getTmin() && 
		tSol<=ray.getTmax();
	    if(isIntersection)
	    {
		glm::vec3 interPoint=ray(tSol);
		glm::vec3 normal=glm::normalize(interPoint-_center);
		intersection.setPoint(interPoint);
		intersection.setNormal(normal);
	    }
	}
	return isIntersection;   
    }

    /**
     * Displays the sphere only for debug purpose.
     */
    void Sphere::displayTTY()const
    {
	cout<<"Sphere"<<"[Center="<<_center;
	cout<<",Radius="<<_radius<<"]"<<endl;
    }

    /**
     * Computes the position of a point on a sphere
     * @param theta the first angle in radian
     * @param phi the second angle in radiant
     * @param r the radius
     * @return the point computed
     */
    inline glm::vec3 spherePoint(double theta, double phi, double r,
				 const glm::vec3 & center)
    {
	double x=r*cos(theta)*sin(phi);
	double y=r*sin(theta)*sin(phi);
	double z=r*cos(phi);

	return glm::vec3(x,y,z)+center;
    }


    /**
     * Computes the normal of a point on a sphere
     * @param theta the first angle in radian
     * @param phi the second angle in radiant
     * @return the normal computed
     */
    inline glm::vec3 sphereNormal(double theta, double phi)
    {
   
	double x=cos(theta)*sin(phi);
	double y=sin(theta)*sin(phi);
	double z=cos(phi);

	return glm::vec3(x,y,z);
    }

    /**
     * Change the mesh representation of the sphere in the
     * rasterisation engine.
     * @param the resolution ie 
     */
    void Sphere::updateMesh(unsigned int resolution)
    {
	_mesh->clear();

	double pi = M_PI;
	double dTheta =(2.0*pi/((double)resolution));
	double dPhi =(1.0*pi/((double)resolution));

	long cmpt =0;

	for(double theta =0 ;theta < (2.0*pi); theta += dTheta)
	{
	    for(double phi =0 ;phi < (1.0*pi); phi += dPhi)
	    {
		_mesh->addVertex(new Vertex(spherePoint(theta, phi, _radius,_center),
					    sphereNormal(theta,phi)));
		_mesh->addVertex(new Vertex(spherePoint(theta+dTheta, phi,_radius,_center),
					    sphereNormal(theta+dTheta,phi)));
		_mesh->addVertex(new Vertex(spherePoint(theta+dTheta,phi+dPhi, _radius,_center),
					    sphereNormal(theta+dTheta,phi+dPhi)));
		_mesh->addVertex(new Vertex(spherePoint(theta,phi+dPhi,_radius,_center),
					    sphereNormal(theta,phi+dPhi)));

		_mesh->addFace(new Face(cmpt,cmpt+1,cmpt+2));
		_mesh->addFace(new Face(cmpt,cmpt+2,cmpt+3));

		cmpt += 4;

	    }
	}

	_mesh->updateVAO();

    }

    /**
     * Return the lastest Mesh computed with the updateMesh
     * method.
     * @return a pointer to the Mesh
     **/
    const Mesh * Sphere::getMesh() const
    {
	return _mesh;
    }

}
