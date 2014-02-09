
/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sat Feb  8 2014
 * 
 */

/**
 * @file Quadratic.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#include "Quadratic.hpp"
namespace math
{

   Quadratic::Quadratic(float a,float b,float c):
      _a(a),_b(b),_c(c)
   {}

   bool Quadratic::solvable() const
   {
      float delta=_b*_b-4*_a*_c;
      std::cout<<"delta="<<delta<<std::endl;
      return delta>=0;
   }

    bool Quadratic::solve(float & minValue,float & maxValue)const
   {
      float delta=_b*_b-4*_a*_c;
      if(delta<0)
      {
	 return false;
      }
      else if(!delta)
      {
	  maxValue=minValue=-_b/(2*_a);
      }
      else
      {
	 float sqrtDelta=std::sqrt(delta);
	 float v1=(-_b-sqrtDelta)/(2*_a);
	 float v2=(-_b+sqrtDelta)/(2*_a);
	 minValue = std::min(v1,v2);
	 maxValue = std::max(v1,v2);
	 
      }
      return true;
   }
}
