/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sat Feb  8 2014
 * 
 */

/**
 * @file Quadric.hpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#ifndef _QUADRIC_HEADER_H
#define _QUADRIC_HEADER_H

#include <iostream>
#include <cmath>
#include <algorithm>
namespace math
{

   class Quadratic
   {
   public :
      Quadratic(float a,float b,float c);
      bool solvable() const;
       bool solve(float & minValue,float & maxValue) const;

   private :
      float _a;
      float _b;
      float _c;

   };
}
#endif
