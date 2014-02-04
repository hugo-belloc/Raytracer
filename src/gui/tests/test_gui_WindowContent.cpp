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
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Tue Feb  4 2014
 * 
 */

/**
 * @file test_gui_WindowContent.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include <iostream>
#include "TriangleContent.hpp"
#include "ImageContent.hpp"
#include "WindowModel.hpp"
#include "WindowView.hpp"

using namespace std;

int main()
{
   gui::WindowView view(200,200);

   gui::WindowModel * model=view.getModel();
   
    model->addContent(new gui::TriangleContent);
   model->addContent(new gui::ImageContent);
   model->nextContent();

   view.beginMainLoop();

   return 0;
}
