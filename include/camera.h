#ifndef CAMERAH
#define CAMERAH

#include <memory>
#include "ray.h"
#include "vec3.h"
#include "scene.h"

using namespace std;
typedef vec3 Point;
typedef vec3 Color;

class Camera{
protected:
	vec3 origin;
	vec3 vertical;
	vec3 horizontal;
	vec3 corner;

public:
	//test
	Camera();

	Camera(Point, Point, Point, Point);

	Color flatColor(const ray&, shared_ptr<Scene> scene);

	Color hitColor(const ray&, shared_ptr<Scene> scene);

	virtual ray traceRay(float, float){}
};

#endif