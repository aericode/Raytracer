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


Color Camera::flatColor(const ray& r, shared_ptr<Scene> scene){
	SurfaceInteraction surfaceInteraction;

	if(scene->intersect(r,MINSIGHT,MAXSIGHT, surfaceInteraction)){
		return surfaceInteraction.primitive->material->color;
	}

	return scene->sampleBG(r);
}


Color Camera::hitColor(const ray& r, shared_ptr<Scene> scene){
	float hitTime = scene->intersect_p(r,MINSIGHT,MAXSIGHT);
	if(hitTime > 0){
		Color result = unit_vector(r.point_at_parameter(hitTime));
		return 0.5*Color(result.x()+1,result.y()+1,result.z()+1);
	}

	return scene->sampleBG(r);
}
