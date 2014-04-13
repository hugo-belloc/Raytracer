/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @author Hicham Benjelloun <hicham.benjelloun@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

#include <sstream>
#include "Scene.hpp"
#include "FileLoader.hpp"
#define EPSILON 1e-6

using namespace std;
namespace scene
{
   
    /**
     * Constructs a Scene
     * @param camera the scene camera.
     */
    Scene::Scene(camera::Camera * camera):
	_prog(),_camera(camera),
	_objects(), _lightPoints(),
	_isProgramUpdated(false)
    { }

    /**
     * Destroy the scene and its camera, its lights
     * and its objects.
     */
    Scene:: ~Scene()
    {
	delete _camera;
	for(iterator_light it=_lightPoints.begin();
	    it!=_lightPoints.end();++it)
	{
	    delete (*it);
	}
	for(iterator_object it=_objects.begin();
	    it!=_objects.end();++it)
	{
	    delete (*it);
	}
    }

    /**
     * Add an object in the scene
     * @param object the object to be added
     */
    void Scene::addObject(scene::Object * object)
    {
	_objects.push_back(object);
    }

    /**
     * Add a light point in the scene.
     * @param lightpoint the lightpoint to be added.
     **/
    void Scene::addLightPoint(light::LightPoint * lightPoint)
    {
	_lightPoints.push_back(lightPoint);
	_isProgramUpdated=false;
    }

    /**
     * Computes the first intersection between a ray and all
     * the Objects of the scene.
     * @param ray the ray to be intersected
     * @param intersection the first intersection computed if
     * there is one
     * @return true if there is an intersection, false otherwise.
     **/
    bool Scene::intersect(const ray::Ray & ray,
			  scene::Intersection & intersection)
    {
	bool isIntersected=false;
	float minDistance=INFINITY;
	Intersection interTest;
	for(iterator_object it=_objects.begin();
	    it!=_objects.end();++it)
	{
	    if((*it)->intersect(ray,interTest))
	    {
		float currentDistance=glm::distance2(interTest.getPoint(),
						     ray.getOrigin());
		if(currentDistance<minDistance)
		{
		    isIntersected=true;
		    minDistance=currentDistance;
		    intersection=interTest;
		}
	    }
	}
	return isIntersected;
    }

    /**
     * @return the Camera of the scene
     */
    camera::Camera* Scene::getCamera()
    {
	return _camera;
    }

    /**
     * @return the Camera of the scene
     */
    const camera::Camera* Scene::getCamera() const
    {
	return _camera;
    }

    /**
     * @return an iterator over the first lightpoint of the scene
     */
    Scene::iterator_light Scene::begin_light()
    {
	return _lightPoints.begin();
    }

    /**
     * @return an iterator over the last lightpoint of the scene
     */
    Scene::iterator_light Scene::end_light()
    {
	return _lightPoints.end();
    }

    /**
     * @return a constant iterator over the first lightpoint of the scene
     */
    Scene::const_iterator_light Scene::begin_light() const
    {
	return _lightPoints.begin();
    }

    /**
     * @return a constant iterator over the last lightpoint of the scene
     */
    Scene::const_iterator_light Scene::end_light() const
    {
	return _lightPoints.end();
    }

    /**
     * @return an iterator over the first object of the scene
     */
    Scene::iterator_object Scene::begin_object()
    {
	return _objects.begin();
    }

    /**
     * @return an iterator over the last object of the scene
     */
    Scene::iterator_object Scene::end_object()
    {
	return _objects.end();
    }

    /**
     * @return a constant iterator over the first object of the scene
     */
    Scene::const_iterator_object Scene::begin_object() const
    {
	return _objects.begin();
    }

    /**
     * @return a constant over the last object of the scene
     */
    Scene::const_iterator_object Scene::end_object() const
    {
	return _objects.end();
    }


    /**
     * This method update the shader of the scene.
     * It is called when the program is updated that
     * when the user asks the program if the program
     * is asked for the first time or if the number of
     * light has changed since the last time.
     */
    void Scene::updateProg()const
    {
	if(! _prog.isEmpty())
	{
	    _prog.clear();
	}
	utils::FileLoader loader;
	std::string vertexShaderCode=
	    loader.loadTextFile("etc/shader.vert");
	std::string fragmentShaderCode=
	    loader.loadTextFile("etc/shader.frag");
	std::string labelText="___LIGHTS_NUMBER___";
	size_t labelPosition=fragmentShaderCode.find(labelText);
	std::ostringstream convert;	    
	convert<<_lightPoints.size();
	fragmentShaderCode.replace(labelPosition,labelText.size(),
				   convert.str());
	_prog.loadFromMemory(vertexShaderCode,
			     fragmentShaderCode);


	_isProgramUpdated=true;
    }

    /**
     *
     * @return a program computed for the Scene
     * with the last number of light
     */
    const utils::Program & Scene::getProgram() const
    {
	if(!_isProgramUpdated)
	{
	    updateProg();
	    _isProgramUpdated=true;
	}

	return _prog;
    }

    /**
     * Compute recursivly the color contribution of one ray.
     * @param currentRay the ray whose contribution is computed.
     * @return the color associated with the ray contribution.
     */
    glm::vec3 Scene::getColor(const ray::Ray & currentRay)
    {
	glm::vec3 color(0,0,0);
	scene::Intersection inter;
	if(intersect(currentRay,inter))
	{
	   glm::vec3 pointHit=inter.getPoint(); 
	   glm::vec3 normalHit=inter.getNormal();
	   glm::vec3 incident = currentRay.getDirection();
	   materials::Material * materialHit=inter.getMaterial();
	   float alpha = 1.0;
	
	    // Part 1 : Light contribution
	    for(iterator_light it=begin_light();
		it!=end_light();++it)
	    {
		glm::vec3 direction=(*it)->getPosition()-pointHit;
		ray::ShadowRay shadowRay(pointHit,direction,0.001,
					 getCamera()->getFarPlan(),1);
		scene::Intersection dummyInter;
		ray::ShadowRay dummyRay(shadowRay);

		float attenuation = 0.0;
		while(intersect(shadowRay,dummyInter))
		{
		    shadowRay.setOrigin(dummyInter.getPoint());
		    attenuation+=1-dummyInter.getMaterial()->getTransmissionAttenuation();
		    if(attenuation >= 1.0)
		    {
			attenuation=1.0;
			break;
		    }
		}

		glm::vec3 matColor= materialHit->computeBRDF(shadowRay,
							     normalHit);
		glm::vec3 lightColor=(*it)->powerAt(pointHit);
		glm::vec3 lightContribution=componentProduct(matColor,
							     lightColor);
		lightContribution = glm::clamp(lightContribution,
					       glm::vec3(0),glm::vec3(1));
		alpha = materialHit->getTransmissionAttenuation();
		color+=(1-attenuation)*(1-alpha)*lightContribution;
		
	    }

	    // Part 2 : Other rays
	    // 2 steps : computing ray direction then getting color recursively
	    if(currentRay.getBounces() > 0)
	    {
		float coeff=fabs(glm::dot(currentRay.getDirection(),normalHit));
		// Reflexion ray
		if(coeff*materialHit->getReflexionAttenuation()>EPSILON)
		{
		    ray::ReflexionRay reflexionRay(pointHit,glm::reflect(incident,normalHit),
						   0.001,getCamera()->getFarPlan(),
						   currentRay.getBounces()-1);
		    color+=coeff*materialHit->getReflexionAttenuation()*
			getColor(reflexionRay);
		}
		// Transmission ray

		float alpha = materialHit->getTransmissionAttenuation();
		alpha*=coeff;
		if(alpha>EPSILON)
		{
		    glm::vec3 dummyVec = glm::dot(incident,normalHit) * normalHit - incident;
		    float sinT1 = glm::dot(dummyVec,dummyVec);
		    float cosT1 = sqrt(fabs(1-sinT1*sinT1));

		    float eta12 = currentRay.getMRI()/materialHit->getMRI();
		    float c = 1-eta12*eta12*sinT1*sinT1;
		    c = (c>0) ? c : 0;
		    float dF1 = (eta12 * cosT1 - sqrt(c)); 
		    glm::vec3 transmittedDirection = eta12 * incident + (dF1 * normalHit); 
		    transmittedDirection = glm::normalize(transmittedDirection);

		    ray::TransmissionRay transmittedRay(pointHit,
							transmittedDirection,
							0.001,
							getCamera()->getFarPlan(),
							currentRay.getBounces()-1,
							(eta12==1.0) ? 1.0 : materialHit->getMRI()
			);	  

		    color+=alpha*getColor(transmittedRay);
		}
	    }
	       
	}
	return color;
    }



}
