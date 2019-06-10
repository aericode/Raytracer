#define BLACK Color(0,0,0)
#include "ray.h"
#include "camera.h"
#include "scene.h"
#include "surfaceInteraction.h"

#define MINSIGHT 0
#define MAXSIGHT 100000

using namespace std;
typedef vec3 Color;
typedef vec3 Point;


Camera::Camera(){}


Camera::Camera(Point origin, Point vertical, Point horizontal, Point corner){
	this->origin     = origin;
	this->vertical   = vertical;
	this->horizontal = horizontal;
	this->corner     = corner;
}


void Camera::changePixel(int x, int y, Color color = BLACK){
	film->changePixel(x,y,color);
}

void Camera::plotFile(){
	film->plotFile();
}
