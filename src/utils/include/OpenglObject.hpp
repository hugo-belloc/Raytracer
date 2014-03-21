/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Fri Mar 21 2014
 * 
 */

/**
 * @file OpenglObject.hpp
 *  
 * 
 */


#ifndef _OPENGLOBJECT_HEADER_H
#define _OPENGLOBJECT_HEADER_H

#include <iostream>

namespace utils
{
   /**
    * A class that represents the objects using openGL.
    */
   class OpenglObject
   {
   public :
      OpenglObject();

   private :
      static bool _isInitialised;

   };
}

#endif
