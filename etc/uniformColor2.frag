#version 330 core

out vec3 color;
in vec3 normal;

uniform vec3 uniformColor;
void main()
{
	color = uniformColor+normal;
}
