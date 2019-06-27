#define MINSIGHT 0
#define MAXSIGHT 100000

#include "blinn_integrator.h"

#include <memory>
#include "ray.h"
#include "scene.h"
#include "surfaceInteraction.h"
#include "material.h"
#include "vec3.h"
#include <algorithm>  

Blinn_integrator::Blinn_integrator(std::shared_ptr<Camera> camera):Sample_integrator(camera){}

Color Blinn_integrator::Li( ray& r, Scene& scene){
	Color result_light(0,0,0);
	Color ambient_result(0,0,0);

	SurfaceInteraction surfaceInteraction;

	if( scene.intersect(r,MINSIGHT,MAXSIGHT, surfaceInteraction) ){
		
		shared_ptr<Material> material = surfaceInteraction.primitive->material;

		vec3 ka = material->ka;
		vec3 kd = material->kd;
		vec3 ks = material->ks;

		for(int i = 0;i < scene.lights.size(); i++ ){
			Light current_light = scene.lights.at(i);
			if( current_light.is_ambient ){
				Color ambient_incident = current_light.intensity * current_light.color;

				ambient_result   = ambient_incident * ka;
			}
		}

		result_light += ambient_result;

		Color final_result = Color ( min(255,(int)(result_light[0]) ), min(255,(int)(result_light[1]) ), min(255,(int)(result_light[3])) );


		return final_result;

	}else{
		return Color(255,255,255);
	}
}