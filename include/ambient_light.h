#ifndef AMBIENTLIGHTH
#define AMBIENTLIGHTH

#include "light.h"
#include "vec3.h"

typedef vec3 Color;

class Ambient_light: public Light{
public:

	Ambient_light();
	Ambient_light(Color, float);
	bool hit();
};


#endif