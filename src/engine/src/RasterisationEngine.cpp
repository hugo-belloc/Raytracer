
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Thu Mar 13 2014
 * 
 */

/**
 * @file RasterisationEngine.cpp
 *  
 * 
 */

#include <sstream>
#include "RasterisationEngine.hpp"

using namespace std;

namespace engine
{

    /**
     * Default constructor nothing to say.
     */
    RasterisationEngine::RasterisationEngine()
    {}

    /**
     * Default destructor nothing to say.
     */
    RasterisationEngine::~RasterisationEngine()
    {}


    /**
     * Draw all the object of a scene.
     * @param scene the scene to be displayed.
     */
    void RasterisationEngine::drawScene(const scene::Scene & scene) const
    {
	const utils::Program & prog=scene.getProgram();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glUseProgram(prog.getId());

      
	//S C E N E   U N I F O R M S
	glm::mat4 viewMat=scene.getCamera()->getViewMatrix();
	prog.setUniform("projectionMatrix",
			scene.getCamera()->getPerspectiveMatrix());
      
	int i=0;
	for(scene::Scene::const_iterator_light it=scene.begin_light();
	    it!=scene.end_light();++it)
	{
	    std::ostringstream convert;	    
	    convert<<i++;
	    std::string lightname="light["+convert.str()+"]";
	    (*it)->setUniforms(prog,lightname,viewMat);  
	}

     
	//O B J E C T S   U N I F O R M S   A N D   D R A W
	for(scene::Scene::const_iterator_object it=scene.begin_object();
	    it!=scene.end_object();++it)
	{
	    scene::Object * obj=*it;
	    glm::mat4 mvw = viewMat*obj->getModelMatrix();
	    prog.setUniform("modelViewMatrix",mvw);
	    glm::mat3 normalMatrix= glm::transpose(glm::inverse(glm::mat3(mvw)));
	    prog.setUniform("normalMatrix", normalMatrix);
	    obj->setUniforms(prog);	
	    obj->draw();
	}

	glUseProgram(0);
	glDisable(GL_DEPTH_TEST);
	glClear(GL_DEPTH_BUFFER_BIT);


    }

}
