#define MINSIGHT 0
#define MAXSIGHT 100000

#include "blinn_integrator.h"

#include "ray.h"
#include "scene.h"
#include "surfaceInteraction.h"
#include "material.h"
#include "vec3.h"

Blinn_integrator::Blinn_integrator(std::shared_ptr<Camera> camera):Sample_integrator(camera){}

Color Blinn_integrator::Li( ray& r, Scene& scene){
	
}