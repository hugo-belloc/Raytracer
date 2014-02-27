/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Thu Feb 20 2014
 * 
 */

/**
 * @file test_scene_Mesh.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#include "Mesh.hpp"
using namespace std;
using namespace scene;
using glm::vec3;

int main()
{
    try
    {
	Mesh myMesh;
	myMesh.addVertex(new Vertex(vec3(-1,-1,-1),vec3(-1,-1,-1)));//0
	myMesh.addVertex(new Vertex(vec3(-1,-1, 1),vec3(-1,-1, 1)));//1
	myMesh.addVertex(new Vertex(vec3(-1, 1,-1),vec3(-1, 1,-1)));//2
	myMesh.addVertex(new Vertex(vec3(-1, 1, 1),vec3(-1, 1, 1)));//3
	myMesh.addVertex(new Vertex(vec3( 1,-1,-1),vec3( 1,-1,-1)));//4
	myMesh.addVertex(new Vertex(vec3( 1,-1, 1),vec3( 1,-1, 1)));//5
	myMesh.addVertex(new Vertex(vec3( 1, 1,-1),vec3( 1, 1,-1)));//6
	myMesh.addVertex(new Vertex(vec3( 1, 1, 1),vec3( 1, 1, 1)));//7
   
	myMesh.addFace(new Face(0,2,1));//f0
	myMesh.addFace(new Face(2,3,1));//f1
	myMesh.addFace(new Face(1,3,7));//f2
	myMesh.addFace(new Face(1,7,5));//f3
	myMesh.addFace(new Face(4,5,6));//f4
	myMesh.addFace(new Face(6,5,7));//f5
	myMesh.addFace(new Face(4,6,2));//f6
	myMesh.addFace(new Face(4,2,0));//f7
	myMesh.addFace(new Face(0,1,4));//f8
	myMesh.addFace(new Face(1,5,4));//f9
	myMesh.addFace(new Face(6,7,2));//f10
	myMesh.addFace(new Face(7,3,2));//f11	
   
	myMesh.displayTTY();

	cout<<"Nombre de vertexs="<<myMesh.getVertexsNumber()<<endl;
	cout<<"Nombre de faces="<<myMesh.getFacesNumber()<<endl;

	Mesh::iterator_vertex itVert=myMesh.begin_vertex();
	Mesh::iterator_face itFace=myMesh.begin_face();

	itVert+=4;
	(*itVert)->displayTTY();
	cout<<"Vertex index="<<myMesh.getVertexIndex(itVert)<<endl;
	itFace+=2;
	cout<<"Face index="<<myMesh.getFaceIndex(itFace)<<endl;

    }
    catch(const exception &e)
    {
	cerr<<e.what()<<endl;
    }    
    return 0;
}
