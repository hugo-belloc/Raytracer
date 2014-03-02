/* -*- c-basic-offset: 3 -*- 
 *
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 * 
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Mar  2 2014
 * 
 */

/**
 * @file FileLoader.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _FILELOADER_HEADER_H
#define _FILELOADER_HEADER_H

#include <iostream>
#include <string>
namespace utils
{
   class FileLoader
   {
   public :
      FileLoader();
      std::string loadTextFile(const std::string &);
   };

}
#endif
