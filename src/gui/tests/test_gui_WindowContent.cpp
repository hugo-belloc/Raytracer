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
#include "RaytracingEngine.hpp"
#include "RasterisationContent.hpp"

#include "Sphere.hpp"
#include "PinholeCamera.hpp"
#include "RaytracingEngine.hpp"

using namespace std;
using namespace glm;
using namespace scene;
using namespace camera;
using namespace engine;
using namespace materials;
using namespace light;
using namespace utils;
using namespace gui;


#define WIDTH 512
#define HEIGHT 512

int main()
{
    gui::WindowView view(WIDTH,HEIGHT);

    sf::Image img;
    img.loadFromFile("etc/chesterfield_arrow512.png");
   
    sf::Image img2;
    img2.create(512,512,sf::Color::Black);

    sf::Image img3;
    img3.loadFromFile("etc/brick_colormap512.tga");
   
    PinholeCamera *cam=new PinholeCamera(vec3(-5,0,0),vec3(0,0,0),
    					 vec3(0,1,0),0.001,1000.f,WIDTH,
    					 HEIGHT,45.f);
   
    Scene scene(cam);
    Object* object = new Object(new Sphere(glm::vec3(0,0,0),1.0),
    				new Material(vec3(0.8,0.8,0.8)),
    				vec3(0,0,0),vec3(180,0,90));
    scene.addObject(object);
    LightPoint *light=new LightPoint(40,vec3(-6,-5,0),vec3(1,1,1),1.0);    
    LightPoint *light2=new LightPoint(20,vec3(-6,5,0),vec3(1,1,1),1.5);

    scene.addLightPoint(light);
    scene.addLightPoint(light2);

    RaytracingEngine engine(&img2);
    engine.raytrace(scene);

    gui::WindowModel * model=view.getModel();
    model->addContent(new gui::TriangleContent);
    gui::ImageContent * myIContent = new gui::ImageContent(&img);
    model->addContent(myIContent);
    myIContent->setImage(&img3);
    model->addContent(new gui::ImageContent(&img2));
    
    model->addContent(new gui::RasterisationContent(scene));
    view.beginMainLoop();
   
    return 0;
}
