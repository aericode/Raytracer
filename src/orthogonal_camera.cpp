#include <iostream>
#include "orthogonal_camera.h"
#include "camera.h"
#include "ray.h"
#include "vec3.h"

typedef vec3 Point;


Orthogonal_camera::Orthogonal_camera(){};

Orthogonal_camera::Orthogonal_camera(Point origin, Point vertical, Point horizontal, Point corner, float direction)
	:Camera(origin,vertical,horizontal,corner){
		this->direction = direction;
	}

ray Orthogonal_camera::traceRay(float x, float y){
	
	Point rayOrigin = corner + x*horizontal + y*vertical;
	//origin moves with target
	Point target = rayOrigin;
	//target's z is a fixed direction
	target[2] = direction;
	//instantiates ray
	ray generated(rayOrigin, target);
	//returns ray
	return generated;

}