#version 330 core

out vec3 color;
uniform vec3 uniformColor;
void main()
{
	color = uniformColor;
}
