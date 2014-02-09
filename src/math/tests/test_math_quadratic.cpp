/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sat Feb  8 2014
 * 
 */

/**
 * @file test_math_quadratic.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include <iostream>
#include "Quadratic.hpp"
using namespace std;
using namespace math;

int main()
{
   Quadratic quad(2.0,-10.0,12.0);
   float minSol,maxSol;
   cout<<quad.solve(minSol,maxSol)<<endl;
   cout<<"Solution="<<minSol<<","<<maxSol<<endl;

   return 0;
}
