/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Thu Feb 20 2014
 * 
 */

#include "Mesh.hpp"
#include "Vao.hpp"
#include "Buffers.hpp"

using namespace std;

namespace scene
{

    /**
     * Create an empty Mesh
     */
    Mesh::Mesh():_vertexs(),_faces()
    {}

    /**
     * Destroy a Mesh with all the vertices and 
     * the Faces in it. Therefore the Vertices 
     * and the Faces added should be deletable 
     * when the Mesh is destroyed.
     */
    Mesh::~Mesh()
    {
	iterator_vertex itVert;      
	for(itVert=begin_vertex();itVert!=end_vertex();++itVert)
	{
	    delete *itVert;
	}

	iterator_face itFace;
	for(itFace=begin_face();itFace!=end_face();++itFace)
	{
	    delete *itFace;
	}
    }

    /**
     * Give the number of vertexs within the Mesh
     * @return the number of vertex within the Mesh
     */
    unsigned int Mesh::getVertexsNumber()const
    {      
	return _vertexs.size();
    }

    /**
     * Give the number of faces within the Mesh.
     * @return the number of faces within the Mesh.
     */
    unsigned int Mesh::getFacesNumber()const
    {
	return _faces.size();
    }

    /**
     * Add a new vertex in the Mesh
     * @param vertex the new vertex to be added
     * @exception std::invalid_argument is thrown if
     * vertex is 0.
     */
    void Mesh::addVertex(Vertex * vertex)
    {
	if(!vertex)
	{
	    throw invalid_argument("Attempt to add a null vertex to a Mesh");
	}
	_vertexs.push_back(vertex);
    }

    /**
     * Add a new face in the Mesh
     * @param face the new face to be added
     * @exception std::invalid_argument is thrown if
     * face is 0.
     */
    void Mesh::addFace(Face* face)
    {
	if(!face)
	{
	    throw invalid_argument("Attempt to add a null face to a Mesh");
	}
	_faces.push_back(face);
    }


    /**
     * Add the given vertex and create a new Face with
     * the vertexs
     * @param v1 the first Vertex to be added
     * @param v2 the second Vertex to be added
     * @param v3 the third Vertex to be added
     */
    void Mesh::addFaceAndVertex(Vertex * v1,Vertex * v2,Vertex *v3)
    {
	unsigned int indiceV1=getVertexsNumber();
	addVertex(v1);
	addVertex(v2);
	addVertex(v3);
	addFace(new Face(indiceV1,indiceV1+1,indiceV1+2));
    }

    /**
     * Return iterator to beginning of the vertexs of the Mesh.
     * @return iterator to beginning of the vertexs of the Mesh.
     */
    Mesh::iterator_vertex Mesh::begin_vertex()
    {
	return _vertexs.begin();
    }

    /**
     * Return iterator to end of the vertexs of the Mesh.
     * @return iterator to end of the vertexs of the Mesh.
     */  
    Mesh::iterator_vertex Mesh::end_vertex()
    {
	return _vertexs.end();
    }

    /**
     * Return iterator to beginning of the vertexs of the Mesh.
     * @return iterator to beginning of the vertexs of the Mesh.
     */
    Mesh::const_iterator_vertex Mesh::begin_vertex() const
    {
	return _vertexs.begin();
    }

    /**
     * Return iterator to end of the vertexs of the Mesh.
     * @return iterator to end of the vertexs of the Mesh.
     */  
    Mesh::const_iterator_vertex Mesh::end_vertex() const
    {
	return _vertexs.end();
    }

    /**
     * Get the index for a given iterator over vertexs
     * @param it an iterator over the vertex of the Mesh.
     * @return the index of the iterator
     */
    unsigned int Mesh::getVertexIndex(const iterator_vertex & it)
    {
	if(it==begin_vertex() && !getVertexsNumber())
	{
	    throw out_of_range("Attempt to get a Vertex index from a Mesh with no Vertex");
	}

	return it-begin_vertex();
    }

    /**
     * Return the beginning of the faces of the Mesh.
     * @return the beginning of the faces of the Mesh.
     */
    Mesh::iterator_face Mesh::begin_face()
    {
	return _faces.begin();
    }

    /**
     * Return the end of the faces of the Mesh
     * @return the end of the faces of the Mesh
     */
    Mesh::iterator_face Mesh::end_face()
    {
	return _faces.end();
    }

    /**
     * Return the beginning of the faces of the Mesh.
     * @return the beginning of the faces of the Mesh.
     */
    Mesh::const_iterator_face Mesh::begin_face() const
    {
	return _faces.begin();
    }

    /**
     * Return the end of the faces of the Mesh
     * @return the end of the faces of the Mesh
     */
    Mesh::const_iterator_face Mesh::end_face() const
    {
	return _faces.end();
    }

    /**
     * Get the index for a given iterator over faces
     * @param it an iterator over the face of the Mesh.
     * @return the index of the iterator
     */
    unsigned int Mesh::getFaceIndex(const iterator_face & it)
    {
	if(it==begin_face() && !getFacesNumber())
	{
	    throw out_of_range("Attempt to get a Face index from a Mesh with no Face");
	}

	return it-begin_face();
    }

    /**
     * Display the Mesh content on the screen
     * usefull for debuggin purpose only.
     */
    void Mesh::displayTTY()const 
    {
	cout<<"Mesh"<<endl<<"["<<endl;
	const_iterator_vertex itVert;      
	for(itVert=begin_vertex();itVert!=end_vertex();++itVert)
	{
	    cout<<" ";
	    (*itVert)->displayTTY();
	}

	const_iterator_face itFace;
	for(itFace=begin_face();itFace!=end_face();++itFace)
	{
	    cout<<" ";
	    (*itFace)->displayTTY();
	}
	cout<<"]"<<endl;
    }

    /**
     * Compute and return the VAO for the Mesh.
     */
    GLuint Mesh::computeVao()
    {
	GLuint positionBuffer,normalBuffer,ibo,vao;
	vector<GLfloat> positions=getPositionArray();
	vector<GLfloat> normals=getNormalArray();
	vector<GLuint> indexs=getIndexArray();      

	glutils::makeVBO(&positionBuffer,&positions[0],
			 positions.size()*sizeof(GLfloat));
	glutils::makeVBO(&normalBuffer,&normals[0],
			 normals.size()*sizeof(GLfloat));
	glutils::makeIBO(&ibo,&indexs[0],indexs.size()*sizeof(GLuint));
	glutils::makeNormalVAO(&vao,positionBuffer,normalBuffer,ibo);
	//glutils::makeSimpleVAO(&vao,positionBuffer,ibo);

	return vao;
    }

    /**
     * @return a vector containing all the position
     * of the vertex in the Mesh
     */
    std::vector<GLfloat> Mesh::getPositionArray()
    {
	vector<GLfloat> positions;
	iterator_vertex itVert;
	for(itVert=begin_vertex();itVert!=end_vertex();++itVert)
	{
	    positions.push_back((*itVert)->getPosition().x);
	    positions.push_back((*itVert)->getPosition().y);
	    positions.push_back((*itVert)->getPosition().z);
	}

	return positions;
    }

    /**
     * @return a vector containing all the normal
     * of the vertex in the Mesh
     */
    std::vector<GLfloat> Mesh::getNormalArray()
    {
	vector<GLfloat> normals;
	iterator_vertex itVert;
	for(itVert=begin_vertex();itVert!=end_vertex();++itVert)
	{
	    normals.push_back((*itVert)->getNormal().x);
	    normals.push_back((*itVert)->getNormal().y);
	    normals.push_back((*itVert)->getNormal().z);
	}

	return normals;
    }

    /**
     * @return a vector containing all the indices
     * used for the Mesh IBO
     */
    std::vector<GLuint> Mesh::getIndexArray()
    {
	vector<GLuint> indexs;
	iterator_face itFace;
	for(itFace=begin_face();itFace!=end_face();++itFace)
	{
	    for(unsigned int i=0;i<3;++i)
	    {
		indexs.push_back((*itFace)->getVertex(i));
	    }
	}
	return indexs;
    }


}
