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

#include <iostream>
#include "gui.hpp"
#include "scene.hpp"
using namespace std;

namespace gui
{
   void testGuiFunction()
   {
      scene::testSceneFunction();
      cout<<"Hi, I am a gui"<<endl;
   }
}
