#include <string>
#include "material.h"
#include "vec3.h"

typedef vec3 Color;

Material::Material(){}

Material::Material(std::string name, Color color){
	this->name  = name;
	this->color = color;
}