#include <string>
#include "material.h"
#include "vec3.h"

typedef vec3 Color;

Material::Material(){}

Material::Material(std::string name, Color color){
	this->name  = name;
	this->color = color;
}

Material::Material(std::string name, vec3 ka, vec3 kd, vec3 ks){
	this->name  = name;
	this->ka    = ka;
	this->kd    = kd;
	this->ks    = ks;
}