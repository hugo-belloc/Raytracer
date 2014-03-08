#version 330 core
// input
layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexNormal;

// output
out vec4 position;
out vec3 normal;

uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;

// material properties
uniform vec3 ambient; 
uniform vec3 diffuse; 

void main()
{
    vec4 positionH=vec4(vertexPosition,1);
    gl_Position =  projectionMatrix * modelViewMatrix *  positionH;
    position=modelViewMatrix * positionH;
    normal=normalize(vertexNormal);
}
 
