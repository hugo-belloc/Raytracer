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

#include <sstream>
#include "Scene.hpp"
#include "FileLoader.hpp"


using namespace std;
namespace scene
{
 
    Scene::Scene(camera::Camera * camera):
	_prog(),_camera(camera),
	_objects(), _lightPoints(),
	_isProgramUpdated(false)
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
	_isProgramUpdated=false;
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

    const camera::Camera* Scene::getCamera() const
    {
	return _camera;
    }

    Scene::iterator_light Scene::begin_light()
    {
	return _lightPoints.begin();
    }

    Scene::iterator_light Scene::end_light()
    {
	return _lightPoints.end();
    }

    Scene::const_iterator_light Scene::begin_light() const
    {
	return _lightPoints.begin();
    }

    Scene::const_iterator_light Scene::end_light() const
    {
	return _lightPoints.end();
    }


    Scene::iterator_object Scene::begin_object()
    {
	return _objects.begin();
    }

    Scene::iterator_object Scene::end_object()
    {
	return _objects.end();
    }

    Scene::const_iterator_object Scene::begin_object() const
    {
	return _objects.begin();
    }

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
}
