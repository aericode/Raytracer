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

	//Buffer where the color of each pixel and image info of the picture are stored
	shared_ptr<Plotter> film;

	Camera();

	//initializes the camera with all the coordinates
	Camera(Point, Point, Point, Point);

	//asks the buffer to change the color of a pixel
	void changePixel(int, int, Color);

	//prints all the pixels of the buffer into a file
	void plotFile();

	//every derived camera must trace a ray
	virtual ray traceRay(float, float){}
};

#endif