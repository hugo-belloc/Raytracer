/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Sun Mar  2 2014
 * 
 */

/**
 * @file test_utils_StringSplitter.cpp
 *  
 */

#include "FileLoader.hpp"
#include "StringSplitter.hpp"

using namespace std;
using namespace utils;

int main()
{
   FileLoader loader;
   StringSplitter splitter;
   string fileContent=loader.loadTextFile("etc/cube.obj");
   vector<string> lines=splitter.split(fileContent,"\n");
   int numberLine=1;

   for(size_t i=0;i<lines.size();++i)
   {
      if(!lines[i].empty() && lines[i][0]!='#')
      {
	 cout<<"Line "<<numberLine<<":";
	 vector<string> lineContent=splitter.splitWhiteSpace(lines[i]);
	 for(size_t j=0;j<lineContent.size();++j)
	 {
	    if(j)
	    {
	       cout<<"|";
	    }
	    cout<<lineContent[j];	    
	 }
	 cout<<endl;
	 ++numberLine;
      }
   }

   return 0;
}
