#ifndef BACKGROUNDH
#define BACKGROUNDH

#include "ray.h"
#include "vec3.h"

typedef vec3 Color;

class Background{
public:
	//list of colors interpolated in the background
	Color interpolate[4];

	//Initializes the background with 4 colors to interpolate
	Background();
	Background(Color*);

	//returns the interpolated color of the point hitted by the ray
	Color sample(const ray&);
};

#endif