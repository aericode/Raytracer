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
	Color result_light(0,0,0);

	if( scene.intersect(r,MINSIGHT,MAXSIGHT, surfaceInteraction) ){
		
		Material material = surfaceInteraction.primitive->material;

		for(int i = 0;i < scene.lights.size(); i++ ){
			if( scene.lights.at(i)->hit()  ){
				ka = 

			}
		}
	}
}