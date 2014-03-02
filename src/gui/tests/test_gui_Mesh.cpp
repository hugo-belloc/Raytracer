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
#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "WindowContent.hpp"
#include "WindowView.hpp"
#include "Mesh.hpp"
#include "PinholeCamera.hpp"
#include "Program.hpp"


using namespace std;
using namespace gui;
using namespace scene;
using namespace utils;
using namespace glm;
using namespace camera;

void setUniforms(Program & prog)
{
    PinholeCamera cam(vec3(-5, 0,0),vec3(0,0,0),
     		      vec3(0,0,1),0.001,1000.f,512,
     		      512,45.f);

    mat4 viewMat=cam.getViewMatrice();
    mat4 modelMat=glm::mat4();
    modelMat=glm::rotate(modelMat,45.0f,vec3(-0.2,-0.3,1));
    modelMat = translate(viewMat*modelMat,vec3(0,0,-0.5));
						     
    prog.setUniform("modelViewMatrix",modelMat);
    prog.setUniform("projectionMatrix",cam.getPerspectiveMatrice());
    prog.setUniform("lightdirn",glm::vec3(-1,0.4,0.0));
    prog.setUniform("lightcolor",glm::vec3(1,1,1));
    prog.setUniform("ambient",glm::vec3(0.1,0.1,0.11));
    prog.setUniform("diffuse",glm::vec3(0.6,0.2,0.2));
    //prog.setUniform("uniformColor",glm::vec3(1.0,0.0,0.0));
    
}

void createCube(Mesh & mesh)
{
    // mesh.addVertex(new Vertex(vec3(-1,-1,-1),vec3(-1,-1,-1)));//0
    // mesh.addVertex(new Vertex(vec3(-1,-1, 1),vec3(-1,-1, 1)));//1
    // mesh.addVertex(new Vertex(vec3(-1, 1,-1),vec3(-1, 1,-1)));//2
    // mesh.addVertex(new Vertex(vec3(-1, 1, 1),vec3(-1, 1, 1)));//3
    // mesh.addVertex(new Vertex(vec3( 1,-1,-1),vec3( 1,-1,-1)));//4
    // mesh.addVertex(new Vertex(vec3( 1,-1, 1),vec3( 1,-1, 1)));//5
    // mesh.addVertex(new Vertex(vec3( 1, 1,-1),vec3( 1, 1,-1)));//6
    // mesh.addVertex(new Vertex(vec3( 1, 1, 1),vec3( 1, 1, 1)));//7
   
    // mesh.addFace(new Face(0,2,1));//f0
    // mesh.addFace(new Face(2,3,1));//f1
    // mesh.addFace(new Face(1,3,7));//f2
    // mesh.addFace(new Face(1,7,5));//f3
    // mesh.addFace(new Face(4,5,6));//f4
    // mesh.addFace(new Face(6,5,7));//f5
    // mesh.addFace(new Face(4,6,2));//f6
    // mesh.addFace(new Face(4,2,0));//f7
    // mesh.addFace(new Face(0,1,4));//f8
    // mesh.addFace(new Face(1,5,4));//f9
    // mesh.addFace(new Face(6,7,2));//f10
    // mesh.addFace(new Face(7,3,2));//f11
    
    glm::vec3 p0(-1,-1,-1);
    glm::vec3 p1( 1,-1,-1);
    glm::vec3 p2( 1,-1, 1);
    glm::vec3 p3(-1,-1, 1);
    glm::vec3 n ( 0,-1, 0);

    glm::vec3 pp0(-1, 1,-1);
    glm::vec3 pp1(-1, 1, 1);
    glm::vec3 pp2( 1, 1, 1);
    glm::vec3 pp3( 1, 1,-1);
    glm::vec3 nn ( 0, 1, 0);

    for(int i=0;i<3;++i)
    {
	int ix=i, iy=(i+1)%3, iz=(i+2)%3;

	//First Face
	mesh.addVertex(new Vertex(vec3(p0[ix],p0[iy],p0[iz]),
				  vec3(n[ix],n[iy],n[iz])));
	mesh.addVertex(new Vertex(vec3(p1[ix],p1[iy],p1[iz]),
				  vec3(n[ix],n[iy],n[iz])));
      	mesh.addVertex(new Vertex(vec3(p2[ix],p2[iy],p2[iz]),
				  vec3(n[ix],n[iy],n[iz])));
	mesh.addVertex(new Vertex(vec3(p3[ix],p3[iy],p3[iz]),
				  vec3(n[ix],n[iy],n[iz])));
	
	mesh.addFace(new Face(8*i,8*i+1,8*i+2));
	mesh.addFace(new Face(8*i,8*i+2,8*i+3));

	//Second Face
	mesh.addVertex(new Vertex(vec3(pp0[ix],pp0[iy],pp0[iz]),
				  vec3(nn[ix],nn[iy],nn[iz])));
	mesh.addVertex(new Vertex(vec3(pp1[ix],pp1[iy],pp1[iz]),
				  vec3(nn[ix],nn[iy],nn[iz])));
      	mesh.addVertex(new Vertex(vec3(pp2[ix],pp2[iy],pp2[iz]),
				  vec3(nn[ix],nn[iy],nn[iz])));
	mesh.addVertex(new Vertex(vec3(pp3[ix],pp3[iy],pp3[iz]),
				  vec3(nn[ix],nn[iy],nn[iz])));
	
	mesh.addFace(new Face(8*i+4,8*i+5,8*i+6));
	mesh.addFace(new Face(8*i+4,8*i+6,8*i+7));		

    }
 
  
}

class MeshContent : public WindowContent
{
public :
MeshContent():_prog()
    {
	_mesh=new Mesh;
	createCube(*_mesh);
	_prog.loadFromFiles("etc/diffuseShader.vert",
			    "etc/diffuseShader.frag");
	_vao=_mesh->computeVao();
	cout<<"VAO:"<<_vao<<endl;
    }

    virtual ~MeshContent()
    {
	glDeleteVertexArrays(1,&_vao);
	delete _mesh;
    }

    virtual void onTransition()
    {}

    virtual void display()
    {
	glEnable(GL_CULL_FACE);
	glUseProgram(_prog.getId());
	setUniforms(_prog);	
	glBindVertexArray(_vao);
	glDrawElements(GL_TRIANGLES,36, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	glUseProgram(0);
	glDisable(GL_CULL_FACE);
    }

private :
    utils::Program _prog;
    GLuint _vao;      
    scene::Mesh * _mesh;
};


// void initShader(Program & prog)
// {
//    prog.loadFromFile("etc/diffuseShader.vert",
// 			"etc/diffuseShader.frag");
   
// }

int main()
{
   WindowView view(512,512);
   WindowModel * model=view.getModel();
   model->addContent(new MeshContent);
   view.beginMainLoop();
   return 0;

}
