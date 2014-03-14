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
uniform vec3 specular;
uniform float shininess;
uniform float opacity;
uniform mat4 modelViewMatrix;

in vec4 position;
in vec3 normal; 


out vec4 fragColor; 

vec3 lightPowerAt(const in Light light,const in vec3 position)
{
   vec3 lightdir = light.position - position;
   float distance2 = dot(lightdir,lightdir)*light.fallOff;
   return ((light.power*light.color)/(distance2));
}

vec3 computeLightLambert(const in Light light,const in vec3 position ,const in vec3 normal, const in vec3 diffuse)
{   
    vec3 lightdir = light.position - position;
    vec3 direction = normalize(lightdir);

    float nDotL = dot(normal, direction);
    vec3 lambert =  lightPowerAt(light,position)*diffuse *max (nDotL, 0.0);  
    return lambert;    
}

vec3 computeLightPhong(const in Light light,const in vec3 position ,const in vec3 normal, const in vec3 mySpecular,const in float myShininess)
{   
    vec3 lightdir = light.position - position;
    vec3 direction = normalize(lightdir);
    vec3 eyedirection = normalize(-position);
    vec3 reflectDir = normalize(reflect(-lightdir,normal));
    float eDotR = max(dot(eyedirection,reflectDir),0.0);
    vec3 phong = lightPowerAt(light,position)* mySpecular * pow(eDotR,myShininess);
    return phong;    
}

vec3 computeLightBlinn(const in Light light,const in vec3 position ,const in vec3 normal, const in vec3 mySpecular,const in float myShininess)
{   
    vec3 lightdir = light.position - position;
    vec3 direction = normalize(lightdir);
    vec3 eyedirection = normalize(-position);
    vec3 halfVector = normalize(eyedirection + lightdir );
    float eDotH = max(dot(normal,halfVector),0.0);
    vec3 blinn = lightPowerAt(light,position)* mySpecular * pow(eDotH,myShininess);
    return blinn;    
}



void main()
{
  vec3 fragNormal = normal;
  fragNormal = normalize(fragNormal);
  vec3 lambert = vec3(0,0,0);
  vec3 specularPart = vec3(0,0,0);
  
  for (int i=0;i<LIGHTS_NUMBER;++i)
  {
	lambert+=computeLightLambert(light[i],
                                     position.xyz*(1/position.w) ,
                                     fragNormal, 
                                     diffuse);
	specularPart+=computeLightBlinn( light[i],position.xyz/position.w, 
                                 fragNormal, specular, 
                                 shininess);
  }
  fragColor= vec4(ambient+lambert+specularPart ,opacity);
}
