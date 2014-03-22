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
#include "Program.hpp"
#include "LightPoint.hpp"
#include "Object.hpp"
#include "Camera.hpp"
#include "ShadowRay.hpp"
#include "ReflexionRay.hpp"
#include "TransmissionRay.hpp"


namespace scene
{

    class Scene
    {
    public :
	typedef std::vector<light::LightPoint*>::iterator iterator_light;
	typedef std::vector<scene::Object*>::iterator iterator_object;
	typedef std::vector<light::LightPoint*>::const_iterator const_iterator_light;
	typedef std::vector<scene::Object*>::const_iterator const_iterator_object;

	Scene(camera::Camera * camera);
	~Scene();
	void addObject(scene::Object * object);
	void addLightPoint(light::LightPoint * lightPoint);
	bool intersect(const ray::Ray & ray,
		       scene::Intersection & intersection);
	camera::Camera *getCamera();
	const camera::Camera *getCamera() const;

	iterator_light begin_light();
	iterator_light end_light();
	const_iterator_light begin_light() const;
	const_iterator_light end_light() const;
	
	iterator_object begin_object();
	iterator_object end_object();
	const_iterator_object begin_object() const;
	const_iterator_object end_object() const;

	 glm::vec3 getColor(const ray::Ray &);

	const utils::Program & getProgram() const;
    private :
	mutable utils::Program _prog;
	void updateProg()const;
	camera::Camera *_camera;
	std::vector<scene::Object*> _objects;
	std::vector<light::LightPoint*> _lightPoints;
	mutable bool _isProgramUpdated;
      
    };
}
#endif
