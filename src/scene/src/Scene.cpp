/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file Scene.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "Scene.hpp"

namespace scene
{
   Scene::Scene(camera::Camera * camera):_camera(camera),_objects(),
					 _lightPoints()
   {}

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

   void Scene::addObject(scene::Object * object)
   {
      _objects.push_back(object);
   }

   void Scene::addLightPoint(light::LightPoint * lightPoint)
   {
      _lightPoints.push_back(lightPoint);
   }

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

   camera::Camera* Scene::getCamera()
   {
      return _camera;
   }

   Scene::iterator_light  Scene::begin()
   {
      return _lightPoints.begin();
   }

   Scene::iterator_light  Scene::end()
   {
      return _lightPoints.end();
   }

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

	
	    // Part 1 : Light contribution
	    for(iterator_light it=begin();
		it!=end();++it)
	       {
		  glm::vec3 direction=(*it)->getPosition()-pointHit;
		  ray::ShadowRay shadowRay(pointHit,direction,0.1,
					   getCamera()->getFarPlan(),1);
		  scene::Intersection dummyInter;
		  if(!intersect(shadowRay,dummyInter))
		     {
			glm::vec3 matColor= materialHit->computeBRDF(shadowRay,
								     normalHit);
			glm::vec3 lightColor=(*it)->powerAt(pointHit);
			glm::vec3 lightContribution=componentProduct(matColor,
								     lightColor);
			color+=lightContribution;
		     }
	       }

	    // Part 2 : Other rays
	    // 2 steps : computing ray direction then getting color recursively

	    if(currentRay.getBounces() > 0) // Test number of bounces remaining
	       {
		  // Reflexion ray
		  glm::vec3 reflectedDirection = incident-2*glm::dot(incident,normalHit)*normalHit;
		  ray::ReflexionRay reflexionRay(pointHit,reflectedDirection,0.1,getCamera()->getFarPlan(),currentRay.getBounces()-1);
		  glm::vec3 reflectedColor = getColor(reflexionRay);
		  color+=materialHit->getReflexionAttenuation()*reflectedColor;

		  // Transmission ray
	       }

	 }

      return color;
   }


}
