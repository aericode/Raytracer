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
		//get the normal of the interaction
		vec3 normal = surfaceInteraction.n;
		//turns it's x y z into a color (based on how much it influentiates the vector)
		int r = ((normal[0] + 1)/2.0 )*255;//x - r
		int g = ((normal[1] + 1)/2.0 )*255;//y - g
		int b = ((normal[2] + 1)/2.0 )*255;//z - b

		//returns the result
		return Color(r,g,b);
	}

	//otherwise get the color of the background
	return scene.sampleBG(r);
}