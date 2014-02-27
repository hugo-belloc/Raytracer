/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Wed Feb 19 2014
 * 
 */

/**
 * @file Face.cpp
 *  
 * Definition of the Face class
 */

#include "Face.hpp"

using namespace std;
namespace scene
{
/**
 * Default constructor. 
 */
   Face::Face():_vertices(3,0)
   {}

/**
 * Construct a face with 3 vertices.
 *
 * @param v1 the indice of the first vertice in the Mesh
 * @param v2 the indice of the second vertice in the Mesh
 * @param v3 the indice of the third vertice in the Mesh
 */
   Face::Face(unsigned int v1,unsigned int v2,unsigned int v3): _vertices()	
   {
      _vertices.push_back(v1);
      _vertices.push_back(v2);
      _vertices.push_back(v3);
   }

   Face::~Face()	
   {}

/**
 * Set the indice for a given vertice.
 * @param num number of the vertice you want to set
 * in the face (should be<=3)
 * @param value the indice of this vertice 
 */
   void Face::setVertex(unsigned int num,unsigned int value)
   {
      if(num>=3)
      {
	 throw out_of_range("Attempt to access a wrong vertices in a Tri");
      }
      _vertices[num]=value;
   }

/**
 * 
 * Get the value of a given vertice.
 * @param num number of the vertice you want to get
 * in the face (should be<=3)
 * @return the indice of the vertice (in the Mesh)
 */
   unsigned int Face::getVertex(unsigned int num) const
   {
      if(num>=3)
      {
	 throw out_of_range("Attempt to access a wrong vertices in a Tri");
      }
      return _vertices[num];
   }

/**
 * Display the value of the Face. For
 * debug purpose.
 */
   void Face::displayTTY()
   {
      cout<<"Face[vertice 0="<<_vertices[0];
      cout<<", vertice 1="<<_vertices[1];
      cout<<", vertice 2="<<_vertices[2]<<"]"<<endl;
   }
}
