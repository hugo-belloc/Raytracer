/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Mar  2 2014
 */

/**
 * @file StringSplitter.cpp
 *  
 */

#include "StringSplitter.hpp"

namespace utils
{
   /**
    * Default constructor .
    */
   StringSplitter::StringSplitter()
   {}
   
   
   /**
    * Split a string with a given delimiter.
    *
    * @param str the string to be splitted.
    * @param delimiter the delimiter used to split
    * the string.
    * @return a std::vector containing all the splitted
    * parts of the string.
    */
   std::vector<std::string> StringSplitter::split(const std::string & str,
						  const std::string & delimiter) const
   {
      std::vector<std::string> result;
      size_t position=0;
      size_t nextPosition;
      size_t len;
      if(str.empty())
	 throw std::invalid_argument("Cannot split an empty string");

      if(delimiter.empty())
	 throw std::invalid_argument("Cannot split a string with an empty delimiter");

      do
      {
	 nextPosition=str.find(delimiter,position);
	 len=(nextPosition==std::string::npos)?
	    std::string::npos:nextPosition-position;
	 result.push_back(str.substr(position,len));
	 position=nextPosition+delimiter.size();
	 
      }while(nextPosition!=std::string::npos);

      return result;
   }


   /**
    * Split a string ignoring the "whitenoise" that is either
    * " " or "\t" or "\n" by default.
    *
    * @param str the string to be splitted.
    * @param delimiter the delimiter used to split
    * the string.
    * @return a std::vector containing all the splitted
    * parts of the string.
    */
   std::vector<std::string> StringSplitter::splitWhiteSpace(const std::string & str) const
   {
      std::string whiteSpace=" \t\n";
      std::vector<std::string> result;
      size_t position=0;
      size_t nextPosition;
      size_t len;

      if(str.empty())
	 throw std::invalid_argument("Cannot split whiteSpace of an empty string");
      do
      {
	 nextPosition=str.find_first_of(whiteSpace,position);
	 len=(nextPosition==std::string::npos)?
	    std::string::npos:nextPosition-position;
	 if(nextPosition!=position)
	    result.push_back(str.substr(position,len));
	 position=nextPosition+1;
	 
      }while(nextPosition!=std::string::npos);

      return result;
   }
 
}
