#version 330 core
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 in_TexCoord0;

out vec2 coordTexture;

void main(){
    vec4 v = vec4(vertexPosition_modelspace,1);
    gl_Position = v;
    coordTexture = in_TexCoord0;
}
