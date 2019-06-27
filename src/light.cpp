#include "vec3.h"
#include "light.h"

Light::Light(){}

Light::Light(Color color, float intensity, bool is_ambient){
	this->color = color;
	this->intensity = intensity;
	this->is_ambient = is_ambient;
}