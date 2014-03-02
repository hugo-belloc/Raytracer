/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Mar  2 2014
 * 
 */

/**
 * @file FileLoader.hpp
 *  
 * Contains the declaration of the FileLoader class.
 * 
 */


#ifndef _FILELOADER_HEADER_H
#define _FILELOADER_HEADER_H

#include <iostream>
#include <string>
#include <stdexcept>

namespace utils
{
   /**
    * A very basic class whose purpose is to load
    * all sort of file. (Just text files are necessary
    * for the moment)
    */
   class FileLoader
   {
   public :
      FileLoader();
      std::string loadTextFile(const std::string & path);
   };

}
#endif
