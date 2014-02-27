#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexNormal;

uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;

out vec3 normal;

void main(){

    vec4 positionH = vec4(vertexPosition,1);
    gl_Position =projectionMatrix * modelViewMatrix * positionH;
    vec4 normalH=projectionMatrix * modelViewMatrix *vec4(vertexNormal,1);
    normal=normalH.xyz;
}

