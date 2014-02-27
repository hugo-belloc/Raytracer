/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Wed Feb 19 2014
 * 
 */

/**
 * @file test_scene_Face.cpp
 *  
 * A simple test for the Face class
 */

#include "Face.hpp"


using namespace std;
using scene::Face;

int main()
{
   Face f1(3,2,1);
   try
   {
      f1.setVertex(0,1);
      f1.setVertex(0,5);
      f1.setVertex(1,8);
      f1.setVertex(2,30);
      f1.displayTTY();
      cout<<f1.getVertex(2)<<endl;
      f1.setVertex(2,30);
   }
   catch(const out_of_range & oor)
   {
      cerr<<"Out of range error:"<<oor.what()<<endl;
   }
   return 0;
}
