/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Feb  9 2014
 * 
 */

/**
 * @file MaterialProperties.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _MATERIALPROPERTIES_HEADER_H
#define _MATERIALPROPERTIES_HEADER_H

#include <iostream>
#include <map>
#include "utils_glm.hpp"
namespace materials
{
   class MaterialProperties
   {
   public :
      MaterialProperties();
      bool hasScalarProperty(const std::string & name)const;
      bool hasVectorProperty(const std::string & name)const;
      float getScalarProperty(const std::string & name)const;
      glm::vec3 getVectorProperty(const std::string & name)const;
      void setScalarProperty(const std::string & name,float value);
      void setVectorProperty(const std::string & name,
			     const glm::vec3 & value );
      void displayTTY()const;

   private :
      std::map<std::string,glm::vec3> _vectorProperties;
      std::map<std::string,float> _scalarProperties;

   };
}
#endif
