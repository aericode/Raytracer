#ifndef BACKGROUNDH
#define BACKGROUNDH

#include "ray.h"
#include "vec3.h"

typedef vec3 Color;

class Background{
public:
	Background();
	Color sample(const ray&);
};

#endif