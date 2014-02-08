/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sat Feb  8 2014
 * 
 */

/**
 * @file Quadric.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#include "Quadric.hpp"
namespace math
{

   Quadric::Quadric(float a,float b,float c):
      _a(a),_b(b),_c(c)
   {}

   bool Quadric::solvable()
   {
      float delta=_b*_b-4*_a*_c;
      return delta>=0;
   }

   bool Quadric::solve(float & value)
   {
      float delta=_b*_b-4*_a*_c;
      if(delta<0)
      {
	 return false;
      }
      else if
      {
	 value=-_b/(2*_a);
      }
      else
      {
	 sqrtDelta=std::sqrt(delta);
	 float v1=(-_b-sqrtDelta)/(2*_a);
	 float v2=(-_b-sqrtDelta)/(2*_a);
	 value = std::min(v1,v2);
      }
      return true;
   }
}
