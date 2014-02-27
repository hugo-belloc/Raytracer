/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Mon Feb 17 2014
 * 
 */

/**
 * @file Vertex.cpp
 *  
 * Definition of the Vertex Class.
 */

#include "Vertex.hpp"

using namespace std;

namespace scene
{
   /**
    * Default constructor
    */
   Vertex::Vertex():_position(),_normal()
   {}

   /**
    * Construct a Vertex with its position and normal
    *
    * @param position the position of the new Vertex
    * @param normal the normal of the new Vertex
    */
   Vertex::Vertex(const glm::vec3 & position,
		  const glm::vec3 & normal):
      _position(position),_normal(normal)
   {}

   /**
    * Give the position of the Vertex.
    *
    * @param position of the Vertex
    */
   const glm::vec3 & Vertex::getPosition() const
   {
      return _position;
   }

   
   /**
    * Give the normal of the Vertex.
    *
    * @param normal of the Vertex
    */
   const glm::vec3 & Vertex::getNormal() const
   {
      return _normal;
   }

  /**
   * Change the position of the Vertex.
   *
   * @author position the new position of the Vertex.
   */
   void Vertex::setPosition(const glm::vec3 & position)
   {
      _position=position;
   }

   /**
   * Change the normal of the Vertex.
   *
   * @author normal the new normal of the Vertex.
   */
   void Vertex::setNormal(const glm::vec3 & normal)
   {
      _normal=normal;
   }

   /**
    * Display the content of the attribute on
    * the terminal. Function for debug/test purpose only!
    */
   void Vertex::displayTTY()
   {
      std::cout<<"Point[position="<<_position;
      std::cout<<", normal="<<_normal<<"]"<<std::endl;
   }
}
