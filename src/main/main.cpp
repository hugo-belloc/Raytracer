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
 * @file main.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include <iostream>
#include "WindowView.hpp"
using namespace std;

int main()
{
   gui::WindowView view(200,200);
   view.display();
   cout<<"I am the main function, I currently do nothing\
 but display an empty window.\n Please come back later..."<<endl;

   return 0;
}
