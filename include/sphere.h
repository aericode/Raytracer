#ifndef SPHEREH
#define SPHEREH
//#define PINKMATERIAL Material("pink", Color(254,127,156))

#include "ray.h"
#include "vec3.h"
#include "primitive.h"
#include "surfaceInteraction.h"
#include "material.h"
#include <memory>

typedef vec3 Point;
typedef vec3 Color;

class Sphere: public Primitive {
public:
	Point center;
	float radius;

	Sphere();
	Sphere(Point, float, std::shared_ptr<Material>);
	~Sphere();
	//checks for collision with sphere and specifies how a ray interacts with the sphere
    bool intersect( const ray& r, float t_min, float t_max, SurfaceInteraction& inter);
    //checks for collision with sphere
    bool intersect_p( const ray& r, float t_min, float t_max);
};

#endif