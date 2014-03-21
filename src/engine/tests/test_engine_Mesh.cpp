/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Mon Feb 10 2014
 * 
 */

/**
 * @file test_engine_RaytracingEngine.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#include "RaytracingEngine.hpp"
#include "PinholeCamera.hpp"
#include "Sphere.hpp"
#include "WindowView.hpp"
#include "Mesh.hpp"
using namespace std;
using namespace glm;
using namespace scene;
using namespace camera;
using namespace engine;
using namespace materials;
using namespace light;
using namespace utils;
using namespace gui;

#include <cmath>


#define WIDTH 512
#define HEIGHT 512

void createCube(Mesh & mesh,const glm::vec3 & center=vec3(0,0,0))
{    
    glm::vec3 p0(-1,-1,-1);
    glm::vec3 p1(+1,-1,-1);
    glm::vec3 p2(+1,-1,+1);
    glm::vec3 p3(-1,-1,+1);
    glm::vec3 n ( 0,-1, 0);

    glm::vec3 pp0(-1,+1,-1);
    glm::vec3 pp1(-1,+1,+1);
    glm::vec3 pp2(+1,+1,+1);
    glm::vec3 pp3(+1,+1,-1);
    glm::vec3 nn ( 0, 1, 0);

    for(int i=0;i<3;++i)
    {
    	int ix=i, iy=(i+1)%3, iz=(i+2)%3;
	int counter=mesh.getVertexsNumber();
    	//First Face
    	mesh.addVertex(new Vertex(center+vec3(p0[ix],p0[iy],p0[iz]),
    				  vec3(n[ix],n[iy],n[iz])));
    	mesh.addVertex(new Vertex(center+vec3(p1[ix],p1[iy],p1[iz]),
    				  vec3(n[ix],n[iy],n[iz])));
      	mesh.addVertex(new Vertex(center+vec3(p2[ix],p2[iy],p2[iz]),
    				  vec3(n[ix],n[iy],n[iz])));
    	mesh.addVertex(new Vertex(center+vec3(p3[ix],p3[iy],p3[iz]),
    				  vec3(n[ix],n[iy],n[iz])));
	
    	mesh.addFace(new Face(counter,counter+1,counter+2));
    	mesh.addFace(new Face(counter,counter+2,counter+3));

    	//Second Face
    	mesh.addVertex(new Vertex(center+vec3(pp0[ix],pp0[iy],pp0[iz]),
    				  vec3(nn[ix],nn[iy],nn[iz])));
    	mesh.addVertex(new Vertex(center+vec3(pp1[ix],pp1[iy],pp1[iz]),
    				  vec3(nn[ix],nn[iy],nn[iz])));
      	mesh.addVertex(new Vertex(center+vec3(pp2[ix],pp2[iy],pp2[iz]),
    				  vec3(nn[ix],nn[iy],nn[iz])));
    	mesh.addVertex(new Vertex(center+vec3(pp3[ix],pp3[iy],pp3[iz]),
    				  vec3(nn[ix],nn[iy],nn[iz])));
	
    	mesh.addFace(new Face(counter+4,counter+5,counter+6));
    	mesh.addFace(new Face(counter+4,counter+6,counter+7));
	 
  
    }
}


int main()
{
    
    //gui::WindowView view(WIDTH,HEIGHT);
    //ensure that Opengl can be used
    sf::Context context;
    glewExperimental=true;
    if (glewInit() != GLEW_OK) 
    {
	std::cerr<<"Failed to initialize GLEW"<<std::endl;
	exit(-1);
    }

    sf::Image img;
    RaytracingEngine engine(&img);
    img.create(WIDTH,HEIGHT,sf::Color(0,0,20));
    PinholeCamera *cam=new PinholeCamera(vec3(-5,0,1),vec3(0,0,0),
					 vec3(0,0,1),0.01,100.f,WIDTH,
					 HEIGHT,45.f);
 
    Sphere *sphere4=new Sphere(vec3(1,1,1),1.0);
    Mesh *triangle= new Mesh;
    triangle->addVertex(new Vertex(vec3(0,-1,+0),vec3(-1,0,0)));
    triangle->addVertex(new Vertex(vec3(0,+1,+0),vec3(-1,0,0)));
    triangle->addVertex(new Vertex(vec3(0,+0,-1),vec3(-1,0,0)));
    triangle->addFace(new Face(0,1,2));
    createCube(*triangle);

    Material *white=new Material(vec3(1,1,1),0,0.0,1.0);
    Material *diffuseRed = new Material(vec3(1,0,0));
   
    Object * whiteSphere=new Object(sphere4,white);
    Object * redTriangle=new Object(triangle,diffuseRed);

    LightPoint *light=new LightPoint(30,vec3(-6,-5,0),vec3(1,1,1),1.0);
    LightPoint *light2=new LightPoint(20,vec3(-6,2,0),vec3(1,1,1),1.0);
    Scene scene(cam);

    scene.addObject(whiteSphere);
    scene.addObject(redTriangle);

    scene.addLightPoint(light);
    scene.addLightPoint(light2);
    engine.raytrace(scene);
    img.saveToFile("img.png");

   
    return 0;
}
