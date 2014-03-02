/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Mar  2 2014
 * 
 */

/**
 * @file FileLoader.cpp
 *  
 * Definition of the FileLoader class.
 */

#include <fstream>
#include "FileLoader.hpp"

namespace utils
{

   /**
    * Default constructor, no data are 
    * need to be supply.
    */ 
   FileLoader::FileLoader()
   {}

   /**
    * Dummy method : load a text file in at string
    *
    * @param path the path to the text file
    * @return a string containing the loaded file.
    * @exception throw std::invalid_argument if the
    * textfile cannot be read.
    */
   std::string FileLoader::loadTextFile(const std::string & path)
   {
      std::string content;
      std::ifstream stream(path, std::ios::in);
      if(!stream.is_open())
      {
	 throw std::invalid_argument("the file "+path+" cannot be read");
      }

      std::string line;
      while(getline(stream, line))
      {
	 content += "\n" + line;
      }
      stream.close();

      return content;
   }

}
