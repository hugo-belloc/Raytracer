/*
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
   gui::WindowView view(512,512);

   sf::Image img;
   img.loadFromFile("etc/chesterfield_arrow512.png");
   
   sf::Image img2;
   img2.create(512,512,sf::Color::Blue);
   for(unsigned int i=0;i+100<img.getSize().x;i++)
   {
      for(unsigned int j=10;j<30;j++)
      {
   	 img2.setPixel(i,j,sf::Color::Red);
      }
   }
   gui::WindowModel * model=view.getModel();
   
   model->addContent(new gui::TriangleContent);
   model->addContent(new gui::ImageContent(img));
   model->addContent(new gui::ImageContent(img2));
   view.beginMainLoop();

   return 0;
}
