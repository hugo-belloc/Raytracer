/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Thu Feb 20 2014
 * 
 */

#include <map>
#include <utility>
#include <sstream>

#include "Mesh.hpp"
#include "Vao.hpp"
#include "Buffers.hpp"
#include "FileLoader.hpp"
#include "StringSplitter.hpp"

#define EPSILON 1e-6

using namespace std;

namespace scene
{

    /**
     * Create an empty Mesh
     */
    Mesh::Mesh():_vertexs(),_faces(),_vao(0),_isVao(false),_bbox()
    {}

    /**
     * Destroy a Mesh with all the vertices and 
     * the Faces in it. 
     */
    Mesh::~Mesh()
    {
	clear();
    }

    /**
     * Clear all the vertexs and the faces of the
     * Mesh and clear the memory.
     */
    void Mesh::clear()
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
	_vertexs.clear();
	_faces.clear();
	if(_isVao)
	{
	    glDeleteVertexArrays(1,&_vao);
	    _vao=0;
	    _isVao=false;
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
	updateBBox();
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
	int i=0;
	const_iterator_vertex itVert;
	for(itVert=begin_vertex();itVert!=end_vertex();++itVert)
	{
	    cout<<" "<<++i<<" ";
	    (*itVert)->displayTTY();
	}

	i=0;
	const_iterator_face itFace;
	for(itFace=begin_face();itFace!=end_face();++itFace)
	{
	    cout<<" "<<++i<<" ";
	    (*itFace)->displayTTY();
	}
	cout<<"]"<<endl;
    }

    /**
     * Compute and the Mesh VAO and update it.
     */
    void Mesh::updateVAO()
    {
	if(_isVao)
	{
	    glDeleteVertexArrays(1,&_vao);
	    _vao=0;
	}
	_isVao=true;

	GLuint positionBuffer,normalBuffer,ibo;
	vector<GLfloat> positions=getPositionArray();
	vector<GLfloat> normals=getNormalArray();
	vector<GLuint> indexs=getIndexArray();      

	utils::makeVBO(&positionBuffer,&positions[0],
		       positions.size()*sizeof(GLfloat));
	utils::makeVBO(&normalBuffer,&normals[0],
		       normals.size()*sizeof(GLfloat));
	utils::makeIBO(&ibo,&indexs[0],indexs.size()*sizeof(GLuint));
	utils::makeNormalVAO(&_vao,positionBuffer,normalBuffer,ibo);
    }

    /**
     * Call the OpenGL routines needed to draw the Mesh
     * (if the openGL context has been well initialised
     * and if a VAO has been computed)
     */
    void Mesh::draw() const
    {
	if(_isVao)
	{
	    glBindVertexArray(_vao);
	    glDrawElements(GL_TRIANGLES,3*getFacesNumber(), GL_UNSIGNED_INT, 0);
	    glBindVertexArray(0);
	}
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

    
    /**
     * Check if whether the Mesh is empty (no faces
     * and no vertexs)
     */
    bool Mesh::empty()
    {
	return _vertexs.empty() && _faces.empty();
    }

    /**
     * An internal function that converts a string 
     * to another integeral type.
     *
     * @param str the string to be converted
     * @param result where the result should be stored
     * @exception throw std::invalid_argument if the string
     * cannot be converted.
     */
    template<typename T>
    void fromStringTo(const std::string & str,T & result )
    {
	std::istringstream iss (str);
	if ((iss>>result).fail())
	    throw std::invalid_argument("Cannot convert string "+str);
    }

    /**
     * If the face is a quad or a triangle, this function triangulate it 
     * and add it to to the face list.
     *
     * @param face the face to be triangulate.
     * @param faceList the
     */
    void triangulateFace(const std::vector<unsigned int> & face,std::vector<Face *> & faceList)
    {
	//If the face is a triangle
	if(face.size()==3)
	{
	    faceList.push_back(new Face(face[0],face[1],face[2]));
	}
	
	//If the face is a quad
	else if(face.size()==4)
	{
	    faceList.push_back(new Face(face[0],face[1],face[2]));
	    faceList.push_back(new Face(face[0],face[2],face[3]));
	}

	//Else throw an exception
	else
	{
	    throw invalid_argument("Cannot triangulate a face that is \
not a quad nor a triangle");
	}	
    }

    /**
     * Load the Mesh geometry from a file in the 
     * OBJ(Wavefront) format.
     * 
     * @param path the path to the OBJ file.
     * @exception  std::invalid_argument is thrown if
     * the file is not a correct OBJ file.
     */
    void Mesh::loadFromOBJFile(const std::string & path)
    {
	utils::FileLoader loader;
	utils::StringSplitter splitter;
	string fileContent=loader.loadTextFile(path);
	vector<string> lines=splitter.split(fileContent,"\n");

	std::vector<glm::vec3> position;
	std::vector<glm::vec3> normal;
	// List of vertex = one postion and on normal from the 
	std::vector<Vertex *> vertexs;
	std::map<std::pair<unsigned int,unsigned int>,unsigned int> vertexIds;
	std::vector<Face *> faces;
	
	unsigned int currentId=0;
	
	//Parsing the position, the normal and the face lines
	for(size_t i=0;i<lines.size();++i)
	{
	    if(!lines[i].empty() && lines[i][0]!='#')
	    {
		vector<string> lineContent=
		    splitter.splitWhiteSpace(lines[i]);
		//Adding the positions in the file in the position list
		if(lineContent[0]=="v")
		{
		    float vertexPos[3];		    
		    for(int j=0;j<3;++j)
		    {
			fromStringTo(lineContent[j+1],vertexPos[j]);
		    }
		    position.push_back(glm::vec3(vertexPos[0],
						 vertexPos[1],
						 vertexPos[2]));
		}
		//Adding the normals in the file in the normals list
		else if(lineContent[0]=="vn")
		{
		    float vertexNormal[3];		    
		    for(int j=0;j<3;++j)
		    {
			fromStringTo(lineContent[j+1],vertexNormal[j]);
		    }
		    normal.push_back(glm::vec3(vertexNormal[0],
					       vertexNormal[1],
					       vertexNormal[2]));
		} 

		else if(lineContent[0]=="f")
		{
		    std::vector<unsigned int> face;
		    for(unsigned int j=1;j<lineContent.size();++j)
		    {
			std::vector<std::string> currentVert=
			    splitter.split(lineContent[j],"/");

			unsigned int positionRef;
			fromStringTo(currentVert[0],positionRef);
			positionRef--;
			unsigned int normalRef;
			fromStringTo(currentVert[2],normalRef);
			normalRef--;
		
			pair<unsigned int,unsigned int> posNormalRefs
			    (positionRef,normalRef);
			
			//cout<<"Refs:"<<positionRef<<" "<<normalRef<<endl;
                        //If the vertex = one element from the position
			// list and one element from the normal list
			// is not found we add it reference
			if(vertexIds.find(posNormalRefs)== vertexIds.end() )
			{
			    vertexIds[posNormalRefs]=currentId++;
			    vertexs.push_back(new Vertex(position[positionRef],
							 normal[normalRef]));
			}
			//Add the vector to the face
			face.push_back(vertexIds[posNormalRefs]);
		    }
		    
		    //Create an actual face from face vector
		    triangulateFace(face,faces);
		}	
	    }
	}

	clear();
	_vertexs=vertexs;
	_faces=faces;

    }

    /**
     * Compute the intersection of a triangle (Face) with a ray
     * @param f the face to intersect with the ray
     * @param ray the ray to intersect
     * @param inter the intersection computed
     * @param t the distance to
     * @return true if there is an intersection false
     * otherwise.
     */
    bool Mesh::intersectTriangle(const Face* f,const ray::Ray & ray,
				 Intersection & inter,float & t) const
    {
	
	Vertex * v1=_vertexs[f->getVertex(0)];
	Vertex * v2=_vertexs[f->getVertex(1)];
	Vertex * v3=_vertexs[f->getVertex(2)];
	
	glm::vec3 e1=v2->getPosition()-v1->getPosition();
	glm::vec3 e2=v3->getPosition()-v1->getPosition();
	
	glm::vec3 rdirxE2 = glm::cross(ray.getDirection(),e2);//P
	float denom = glm::dot(e1,rdirxE2);

	//If the ray is parallele to the triangle plan
	if(denom<EPSILON && denom>-EPSILON)
	{

	    return false;	    
	}
	float invDenom=1/denom;

	glm::vec3 orig2v1 = ray.getOrigin()-v1->getPosition();//T	
	float u,v;
	u = glm::dot(rdirxE2,orig2v1)*invDenom;
	if(u<0 || u>1)
	{
	    return false;	    
	}
	glm::vec3 orig2v1xE1  = glm::cross(orig2v1,e1);//Q
	v = glm::dot(orig2v1xE1,ray.getDirection())*invDenom;
	if(v<0 || u+v>1)
	{
	    return false;	    
	}
	t= glm::dot(orig2v1xE1,e2)*invDenom;
	if(t>ray.getTmax() || t<ray.getTmin())
	{
	    return false;	    
	}

	float w = 1-u-v;
	inter.setPoint(ray(t));
	inter.setNormal(glm::normalize(w*v1->getNormal()+
				       u*v2->getNormal()+
				       v*v3->getNormal()));

	return true;
    }

    /* Computes the intersection between a ray and the Mesh
     * in local space
     * @param the ray to be intersected
     * @param intersection the generated intersection 
     * if there is one
     * @return true if there is an intersection , false otherwise.
     */
    bool Mesh::intersect(const ray::Ray & ray,
			 Intersection & inter)const
    {
	float tmin=INFINITY;
	bool isIntersected=false;
	Intersection currentInter;
	float t;
	const_iterator_face itFace;

	if(!_bbox.intersect(ray))
	{
	    return false;
	}

	for(itFace=begin_face();itFace!=end_face();++itFace)
	{
	    
	    if(intersectTriangle(*itFace,ray,currentInter,t) && t<tmin)
	    {
		tmin=t;
		isIntersected=true;
		inter=currentInter;	
	    }
	}
	return isIntersected;
    }

    /**
     * Update the VAO associated with the mesh.
     */ 
    void Mesh::updateMesh(unsigned int)
    {
	//Do nothing since the mesh is a mesh itself...
	updateVAO();
    }

    /**
     * Returns the mesh itself
     */
    const Mesh * Mesh::getMesh() const
    {
	//return itself
	return this;
    }

    /**
     * Computes the BoundingBox surrounding the Mesh
     */
    void Mesh::updateBBox()
    {
	iterator_vertex itVert;
	for(itVert=begin_vertex();itVert!=end_vertex();++itVert)
	{
	    _bbox.surroundPoint((*itVert)->getPosition());
	}
    }

}
