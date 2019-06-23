#define MINSIGHT 0
#define MAXSIGHT 100000

#include "normal_integrator.h"

#include "ray.h"
#include "scene.h"
#include "surfaceInteraction.h"
#include "material.h"
#include "vec3.h"

Normal_integrator::Normal_integrator(std::shared_ptr<Camera> camera):Sample_integrator(camera){}

Color Normal_integrator::Li( ray& r, Scene& scene){
	SurfaceInteraction surfaceInteraction;

	if(scene.intersect(r,MINSIGHT,MAXSIGHT, surfaceInteraction)){
		vec3 normal = surfaceInteraction.n;

		int r = ((normal[0] + 1)/2.0 )*255;
		int g = ((normal[1] + 1)/2.0 )*255;
		int b = ((normal[2] + 1)/2.0 )*255;

		return Color(r,g,b);
	}

	return scene.sampleBG(r);
}