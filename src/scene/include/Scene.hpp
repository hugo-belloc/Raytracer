/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file Scene.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _SCENE_HEADER_H
#define _SCENE_HEADER_H

#include <iostream>
#include <vector>
#include <iterator>
#include "utils_glm.hpp"
#include "Ray.hpp"
#include "Intersection.hpp"
#include "LightPoint.hpp"
#include "Object.hpp"
#include "Camera.hpp"
#include "ShadowRay.hpp"
#include "ReflexionRay.hpp"

namespace scene
{
   class Scene
   {
   public :
      typedef std::vector<light::LightPoint*>::iterator iterator_light;
      typedef std::vector<scene::Object*>::iterator iterator_object;
      Scene(camera::Camera * camera);
      ~Scene();
      void addObject(scene::Object * object);
      void addLightPoint(light::LightPoint * lightPoint);
      bool intersect(const ray::Ray & ray, scene::Intersection & intersection);
      camera::Camera *getCamera();
      iterator_light  begin();
      iterator_light  end();

      glm::vec3 getColor(const ray::Ray &);

   private :
      camera::Camera *_camera;
      std::vector<scene::Object*> _objects;
      std::vector<light::LightPoint*> _lightPoints;
      
   };
}
#endif
