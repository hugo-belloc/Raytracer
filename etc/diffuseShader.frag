#version 330 core

//NOTE the following __LIGHTS_NUMBER__ is a label and 
//is going to be replaced by a value when the program loads the shader.
#define LIGHTS_NUMBER ___LIGHTS_NUMBER___

//Light property
// Assume that light is punctual and anisotropic
struct Light
{
    float power;
    vec3 position;
    vec3 color;
    float fallOff;
};
uniform Light light[LIGHTS_NUMBER];

// material properties
uniform vec3 ambient; 
uniform vec3 diffuse;
uniform float transparency;

in vec4 position;
in vec3 normal; 


out vec4 fragColor; 


vec3 ComputeLightLambert(const in Light light,const in vec3 position ,const in vec3 normal, const in vec3 mydiffuse)
{   
    vec3 diff = light.position - position;
    vec3 direction = normalize(diff);
    float distance2 = dot(diff,diff)*light.fallOff;

    float nDotL = dot(normal, direction);
    vec3 lambert = ((light.power*light.color)/(distance2)) *mydiffuse * max (nDotL, 0.0);  
    return lambert;
}


void main()
{
  vec3 fragNormal = normal;
  fragNormal = normalize(fragNormal);
  vec3 lambert = vec3(0,0,0);
  
  for (int i=0;i<LIGHTS_NUMBER;++i)
  {
	lambert+=ComputeLightLambert(light[i], position.xyz*(1/position.w) ,fragNormal, diffuse);
  }
  fragColor= vec4(ambient+lambert,transparency);
}
