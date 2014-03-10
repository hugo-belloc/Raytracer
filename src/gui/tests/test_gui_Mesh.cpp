/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Thu Feb 20 2014
 * 
 */

/**
 * @file test_gui_Mesh.cpp
 *  
 * Test of the Mesh class (graphically)
 * using the gui API with a custom WindowContent
 */

#include "utils_glm.hpp"
#include <cmath>
#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <string>
#include <sstream>

#include "FileLoader.hpp"
#include "WindowContent.hpp"
#include "WindowView.hpp"
#include "Mesh.hpp"
#include "Sphere.hpp"
#include "PinholeCamera.hpp"
#include "Program.hpp"
#include "LightPoint.hpp"
#include "Material.hpp"

using namespace std;
using namespace gui;
using namespace scene;
using namespace utils;
using namespace glm;
using namespace camera;
using namespace light;
using namespace materials;

inline glm::vec3 torusPoint(double theta, double phi, double R, double r)
{
    double x=(R+r*cos(phi))*cos(theta);
    double y=(R+r*cos(phi))*sin(theta);
    double z=r*sin(phi);

    return glm::vec3(x,y,z);
}

inline glm::vec3 torusNormal(double theta, double phi)
{
   
    double x=cos(phi)*cos(theta);
    double y=sin(theta);
    double z=sin(phi);

    return glm::vec3(x,y,z);
}

void createTorus(Mesh & mesh,double R,double r,int nbBins)
{
    mesh.clear();

    double pi = M_PI;
    double delta =(2.0*pi/((double)nbBins));
    long cmpt =0;

    for(double theta =0 ;theta < (2.0*pi); theta += delta)
    {
        for(double phi =0 ;phi < (2.0*pi); phi += delta)
        {
            mesh.addVertex(new Vertex(torusPoint(theta, phi, R, r),
				      torusNormal(theta,phi)));
	    mesh.addVertex(new Vertex(torusPoint(theta+delta, phi, R, r),
				      torusNormal(theta+delta,phi)));
	    mesh.addVertex(new Vertex(torusPoint(theta+delta,phi+delta, R, r),
				      torusNormal(theta+delta,phi+delta)));
            mesh.addVertex(new Vertex(torusPoint(theta,phi+delta, R, r),
				      torusNormal(theta,phi+delta)));

	    mesh.addFace(new Face(cmpt,cmpt+1,cmpt+2));
	    mesh.addFace(new Face(cmpt,cmpt+2,cmpt+3));

            cmpt += 4;

        }
    }
}



inline glm::vec3 spherePoint(double theta, double phi, double r)
{
    double x=r*cos(theta)*sin(phi);
    double y=r*sin(theta)*sin(phi);
    double z=r*cos(phi);

    return glm::vec3(x,y,z);
}

inline glm::vec3 sphereNormal(double theta, double phi)
{
   
    double x=cos(theta)*sin(phi);
    double y=sin(theta)*sin(phi);
    double z=cos(phi);

    return glm::vec3(x,y,z);
}

void createSphere(Mesh & mesh,double r,int resolution)
{
    mesh.clear();

    double pi = M_PI;
    double dTheta =(2.0*pi/((double)resolution));
    double dPhi =(1.0*pi/((double)resolution));

    long cmpt =0;

    for(double theta =0 ;theta < (2.0*pi); theta += dTheta)
    {
        for(double phi =0 ;phi < (1.0*pi); phi += dPhi)
        {
            mesh.addVertex(new Vertex(spherePoint(theta, phi, r),
				      sphereNormal(theta,phi)));
	    mesh.addVertex(new Vertex(spherePoint(theta+dTheta, phi, r),
				      sphereNormal(theta+dTheta,phi)));
	    mesh.addVertex(new Vertex(spherePoint(theta+dTheta,phi+dPhi, r),
				      sphereNormal(theta+dTheta,phi+dPhi)));
            mesh.addVertex(new Vertex(spherePoint(theta,phi+dPhi, r),
				      sphereNormal(theta,phi+dPhi)));

	    mesh.addFace(new Face(cmpt,cmpt+1,cmpt+2));
	    mesh.addFace(new Face(cmpt,cmpt+2,cmpt+3));

            cmpt += 4;

        }
    }
}


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



class MeshContent : public WindowContent
{
public :
    MeshContent(const Mesh * mesh):_prog(),_mesh(mesh),
				   _cam(vec3(-5, 0,0),vec3(0,0,0),
					vec3(0,0,1),0.01,100.f,512,
					512,45.f),
				   _material(vec3(0.8,0.8,0.8)),
				   _lights()
    {
	FileLoader loader;
	string vertexShaderCode=
	    loader.loadTextFile("etc/diffuseShader.vert");
	string fragmentShaderCode=
	    loader.loadTextFile("etc/diffuseShader.frag");
	string labelText="___LIGHTS_NUMBER___";
	size_t labelPosition=fragmentShaderCode.find(labelText);
	fragmentShaderCode.replace(labelPosition,labelText.size(),"2");
	_prog.loadFromMemory(vertexShaderCode,
			     fragmentShaderCode);

	_lights.push_back(new LightPoint(5.f,vec3(-5.0f,0,3),
					 vec3(0.3,1,0.3),0.2f));
	_lights.push_back(new LightPoint(5.f,vec3(-5.0f,0,-3),
					 vec3(0.3,0.3,1),0.2f));

    }

    virtual ~MeshContent()
    {
	glDeleteVertexArrays(1,&_vao);
	delete _mesh;
	for(unsigned int i=0;i<_lights.size();++i)
	    delete _lights[i];
    }

    virtual void onTransition()
    {}

    virtual void display()
    {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);

	glUseProgram(_prog.getId());
	setUniforms();	
	_mesh->draw();
	glUseProgram(0);

	glDisable(GL_DEPTH_TEST);
	glClear(GL_DEPTH_BUFFER_BIT);
    }

private :
    void setUniforms()
    {
	mat4 viewMat=_cam.getViewMatrice();
	mat4 modelMat=glm::mat4();

	modelMat=glm::rotate(modelMat,-90.0f,vec3(0,0,1));
	modelMat=glm::rotate(modelMat,180.0f,vec3(1,0,0));
	modelMat = translate(modelMat,vec3(0,0,0.2));

	mat4 mvw = viewMat*modelMat;
						     

	_prog.setUniform("modelViewMatrix",mvw);
	_prog.setUniform("projectionMatrix",_cam.getPerspectiveMatrice());
	mat3 normalMatrix= transpose(inverse(mat3(mvw)));
	_prog.setUniform("normalMatrix", normalMatrix);

	
	for(unsigned int i=0;i<_lights.size();++i)
	{
	    std::ostringstream convert;	    
	    convert<<i;
	    std::string lightname="light["+convert.str()+"]";
	    _lights[i]->setLightUniforms(_prog,lightname,viewMat);  
	}
	_material.setMaterialUniforms(_prog);
    
    }

    
    Program _prog;
    GLuint _vao;      
    const scene::Mesh * _mesh;
    PinholeCamera _cam;
    Material _material;
    vector<LightPoint *> _lights;
};


int main(int argc,char * argv[])
{
    if(argc != 2)
    {
	cerr<<"Bad number of argument"<<endl;
	return -1;
    }
    
    WindowView view(512,512);
    WindowModel * model=view.getModel();
    Mesh * mesh=new Mesh;
    std::string input(argv[1]);
    Sphere sphere(glm::vec3(0,0,0),1.0);

    if(input=="cube")
    {
	createCube(*mesh);
    }
    else if(input=="torus")
    {
	createTorus(*mesh,0.75,0.25,30);
    }
    else if(input=="sphere")
    {
	createSphere(*mesh,1.0,30);
	
	//sphere.updateMesh(30);
	//model->addContent(new MeshContent(sphere.getMesh()));
	
    }
    
    else
	mesh->loadFromOBJFile(argv[1]);

    mesh->updateVAO();
    model->addContent(new MeshContent(mesh));

    view.beginMainLoop();
    return 0;

}
