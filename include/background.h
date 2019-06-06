#ifndef BACKGROUNDH
#define BACKGROUNDH

#include "ray.h"
#include "vec3.h"

typedef vec3 Color;

class Background{
public:
	Color interpolate[4];

	Background();
	Background(Color*);
	Color sample(const ray&);
};

#endif