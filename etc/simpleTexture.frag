#version 330 core

in vec2 coordTexture;
uniform sampler2D textureSampler;
out vec4 out_Color;

void main()
{
    out_Color = texture(textureSampler, coordTexture);
}
