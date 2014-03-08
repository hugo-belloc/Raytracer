#version 330 core

// Assume light is directional
uniform vec3 lightdirn; 
uniform vec3 lightcolor; 
// material properties
uniform vec3 ambient; 
uniform vec3 diffuse;
uniform float transparency;

in vec4 position;
in vec3 normal; 


out vec4 fragColor; 


vec3 ComputeLightLambert(const in vec3 lightdirn, const in vec3 lightcolor, const in vec3 normal, const in vec3 mydiffuse)
{    
    float nDotL = dot(normal, lightdirn);
    vec3 lcolor=lightcolor;
    vec3 lambert = mydiffuse * lcolor * max (nDotL, 0.0);  
    return lambert;
}


void main()
{
  fragColor=vec4(ambient,0);
  vec3 fragNormal = normal;
  fragNormal = normalize(fragNormal); 
  vec3 lambert = ComputeLightLambert(lightdirn, lightcolor, fragNormal, diffuse);
  fragColor= fragColor+vec4(lambert,transparency);
}
