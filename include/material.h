#ifndef MATERIALH
#define MATERIALH

#include "vec3.h"
#include <string>

typedef vec3 Color;

class Material{
public:
	Material();
	Material(std::string, Color);
	Material(std::string, vec3, vec3, vec3);
	Color color;
	std::string name;

	vec3 ka;
	vec3 kd;
	vec3 ks;

};

#endif