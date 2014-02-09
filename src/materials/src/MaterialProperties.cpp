
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file MaterialProperties.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */
#include <cstdlib>
#include <cstdio>
#include "MaterialProperties.hpp"
#include <iterator>

using namespace std;
namespace materials
{

   MaterialProperties::MaterialProperties():_vectorProperties(),_scalarProperties()
   {}

   bool MaterialProperties::hasScalarProperty(const std::string & name)const
   {
      return _scalarProperties.count(name)>0;
   }
   bool MaterialProperties::hasVectorProperty(const std::string & name)const
   {
      return _vectorProperties.count(name)>0;
   }
   
   float  MaterialProperties::getScalarProperty(const std::string & name)const
   {
      if(!hasScalarProperty(name))
      {
	 cerr<<"Scalar property "<<name<<" does not exist"<<endl;
	 exit(-1);
      }
      return _scalarProperties.at(name);
   }

   glm::vec3 MaterialProperties::getVectorProperty(const std::string & name)const
   {
      if(!hasVectorProperty(name))
      {
	 cerr<<"Vector property "<<name<<" does not exist"<<endl;
	 exit(-1);
      }
      return _vectorProperties.at(name);
   }
      
   void  MaterialProperties::setScalarProperty(const std::string & name,
					       float value)
   {
      _scalarProperties[name]=value;
   }

   void  MaterialProperties::setVectorProperty(const std::string & name,
					       const glm::vec3 & value )
   {
      _vectorProperties[name]=value;
   }

   void MaterialProperties::displayTTY()const
   {
      bool init=true;
      for(map<string,glm::vec3>::const_iterator it=_vectorProperties.begin();
	  it!=_vectorProperties.end();++it)
      {
	 if(!init)
	    cout<<",";
	 cout<<it->first<<"="<<it->second;
	 cout<<" ";
	 init=false;
      }
      
      for(map<string,float>::const_iterator it=_scalarProperties.begin();
	  it!=_scalarProperties.end();++it)
      {
	 if(!init)
	    cout<<",";
	 cout<<it->first<<"="<<it->second;
	 cout<<" ";
	 init=false;
      }
   }

}
