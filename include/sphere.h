#ifndef SPHEREH
#define SPHEREH
#define PINKMATERIAL Material("pink", Color(254,127,156))

#include "ray.h"
#include "vec3.h"
#include "primitive.h"
#include "surfaceInteraction.h"
#include "material.h"

typedef vec3 Point;
typedef vec3 Color;

class Sphere: public Primitive {
public:
	Point center;
	float radius;

	Sphere();
	Sphere(Point, float, Material = PINKMATERIAL);
	~Sphere();

    bool intersect( const ray& r, float t_min, float t_max, SurfaceInteraction& inter);

    bool intersect_p( const ray& r, float t_min, float t_max);
};

#endif