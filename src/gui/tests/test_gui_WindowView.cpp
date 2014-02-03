#include <iostream>
#include "WindowView.hpp"
using namespace std;

int main()
{
   gui::WindowView view(200,200);
   view.beginMainLoop();
   view.resize(500,500);
   int i;
   cin>>i;
   view.beginMainLoop();
   return 0;
}

