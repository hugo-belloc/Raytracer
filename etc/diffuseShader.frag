#version 330 core


struct Light
{
    float intensity;
    vec3 color;
    vec3 direction;
};

// Assume light is directional
//uniform vec3 lightdirn; 
//uniform vec3 lightcolor;
uniform Light light;

// material properties
uniform vec3 ambient; 
uniform vec3 diffuse;
uniform float transparency;

in vec4 position;
in vec3 normal; 


out vec4 fragColor; 


vec3 ComputeLightLambert(const in Light light, const in vec3 normal, const in vec3 mydiffuse)
{    
    float nDotL = dot(normal, light.direction);
    vec3 lcolor=light.color;
    vec3 lambert = light.intensity*mydiffuse * lcolor * max (nDotL, 0.0);  
    return lambert;
}


void main()
{
  vec3 fragNormal = normal;
  fragNormal = normalize(fragNormal); 
  vec3 lambert = ComputeLightLambert(light, fragNormal, diffuse);
  fragColor= vec4(ambient+lambert,transparency);
}
