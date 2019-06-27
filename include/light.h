#ifndef LIGHTH
#define LIGHTH

#include "vec3.h"

typedef vec3 Color;

class Light{
public:
	Color color;
	float intensity;
	bool is_ambient;

	Light();
	Light(Color, float, bool);
};

#endif