/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Mon Feb 17 2014
 * 
 */

/**
 * @file Mesh.hpp
 *  
 * Contains the Mesh class declaration
 */


#ifndef _MESH_HEADER_H
#define _MESH_HEADER_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "utils_glm.hpp"
#include <GL/glew.h>

#include "Vertex.hpp"
#include "Face.hpp"
#include "Shape.hpp"
#include "BoundingBox.hpp"

namespace scene
{
    /**
     * This class is a representation of a Mesh made
     * with Vertexs and Faces.
     */
    class Mesh : public Shape
    {
    public :
	/**
	 * This type iterate over the Vertexs within the Mesh
	 */
	typedef std::vector<Vertex*>::iterator iterator_vertex;

	/**
	 * This type iterate over the Faces within th Mes
	 */
	typedef std::vector<Face*>::iterator iterator_face;
	/**
	 * This type iterate over the Vertexs within the Mesh
	 */
	typedef std::vector<Vertex*>::const_iterator const_iterator_vertex;

	/**
	 * This type iterate over the Faces within th Mes
	 */
	typedef std::vector<Face*>::const_iterator const_iterator_face;

	Mesh();
	virtual ~Mesh();
	void clear();
	unsigned int getVertexsNumber()const;
	unsigned int getFacesNumber()const;
	void addVertex(Vertex * vertex);
	void addFace(Face* face);
	void addFaceAndVertex(Vertex * v1,Vertex * v2,Vertex *v3);

	iterator_vertex begin_vertex();
	iterator_vertex end_vertex();
	const_iterator_vertex begin_vertex() const;
	const_iterator_vertex end_vertex() const;
	unsigned int getVertexIndex(const iterator_vertex & it);
	iterator_face begin_face();
	iterator_face end_face();
	const_iterator_face begin_face() const;
	const_iterator_face end_face() const;
	unsigned int getFaceIndex(const iterator_face & it);
	
	void updateVAO();
	void draw() const;
		
	bool empty();
	
	void loadFromOBJFile(const std::string & path);

	// Methods of th Shape interface
	virtual bool intersect(const ray::Ray & ray,
			       Intersection & inter)const;
	virtual void displayTTY()const;
	virtual void updateMesh(unsigned int resolution);
	virtual const Mesh * getMesh() const;
	void updateBBox();
	
    private :
	
	bool intersectTriangle(const Face* f,const ray::Ray & ray,
			       Intersection & inter,float & t)const;

	std::vector<GLfloat> getPositionArray();
	std::vector<GLfloat> getNormalArray();
	std::vector<GLuint> getIndexArray();
	

	std::vector<Vertex*> _vertexs;
	std::vector<Face*> _faces;
	GLuint _vao;
	bool _isVao;
	BoundingBox _bbox;
       
    };

}
#endif
