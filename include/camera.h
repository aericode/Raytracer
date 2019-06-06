#ifndef CAMERAH
#define CAMERAH

#include <memory>
#include "ray.h"
#include "vec3.h"
#include "scene.h"
#include "plotter.h"

class Scene;

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

	shared_ptr<Plotter> film;

	//test
	Camera();

	Camera(Point, Point, Point, Point);

	Color flatColor(const ray&, shared_ptr<Scene> scene);

	Color hitColor(const ray&, shared_ptr<Scene> scene);

	void changePixel(int, int, Color);

	void plotFile();

	virtual ray traceRay(float, float){}
};

#endif