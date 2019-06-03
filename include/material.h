#ifndef MATERIALH
#define MATERIALH

#include "vec3.h"
#include <string>

typedef vec3 Color;

class Material{
public:
	Material();
	Material(std::string, Color);
	Color color;
	std::string name;

};

#endif