/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file Object.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include "Object.hpp"
using namespace std;

namespace scene
{
   Object::Object(scene::Shape * shape,
		  materials::Material * material):_shape(shape),
						  _material(material)
   {}

   Object::~Object()
   {
      delete _shape;
      delete _material;
   }

   bool Object::intersect(const ray::Ray & ray,
		  Intersection & intersection)const
   {
      bool isIntersected= _shape->intersect(ray,intersection);
      if(isIntersected)
      {
	 intersection.setMaterial(getMaterial());
      }
      return isIntersected  ;
   }

  materials::Material * Object::getMaterial()const
  {
     return _material;
  }

   void Object::diplayTTY()const
   {
      cout<<"Material"<<endl<<"["<<endl;
      cout<<"   "<<endl;
      _shape->displayTTY();
      cout<<"   "<<endl;
      _material->displayTTY();
      cout<<"]"<<endl<<endl;
   }
}






















