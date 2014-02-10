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

   Scene:: iterator_light  Scene::end()
   {
      return _lightPoints.end();
   }
}
