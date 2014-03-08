/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Mar  2 2014
 */

/**
 * @file StringSplitter.hpp
 *  
 */


#ifndef _STRINGSPLITTER_HEADER_H
#define _STRINGSPLITTER_HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

namespace utils
{
   /**
    * This class simplify string parsing by allowing 
    * to split with a given delimiter.
    */
   class StringSplitter
   {
   public :
      StringSplitter();
      std::vector<std::string> split(const std::string & str,
				const std::string & delimiter) const;
      std::vector<std::string> splitWhiteSpace(const std::string & str) const ;
            
   };
}
#endif
