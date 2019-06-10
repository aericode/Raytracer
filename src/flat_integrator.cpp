#define MINSIGHT 0
#define MAXSIGHT 100000

#include "flat_integrator.h"

#include "ray.h"
#include "scene.h"
#include "surfaceInteraction.h"
#include "material.h"
#include "vec3.h"

Flat_integrator::Flat_integrator(std::shared_ptr<Camera> camera):Sample_integrator(camera){}

Color Flat_integrator::Li( ray& r, Scene& scene){
	SurfaceInteraction surfaceInteraction;

	if(scene.intersect(r,MINSIGHT,MAXSIGHT, surfaceInteraction)){
		return surfaceInteraction.primitive->material->color;
	}

	return scene.sampleBG(r);
}