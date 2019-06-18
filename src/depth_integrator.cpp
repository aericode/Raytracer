#define MINSIGHT 0
#define MAXSIGHT 100000

#include "depth_integrator.h"

#include "ray.h"
#include "scene.h"
#include "surfaceInteraction.h"
#include "material.h"
#include "vec3.h"

void Depth_integrator::preprocess(Scene& scene){
	float zMin = MAXSIGHT; //inicia como max para ser substituído por um menor
	float zMax = MINSIGHT; //inicia como max para ser substituído por um maior

	int nx = scene.camera->film->xSize;
	int ny = scene.camera->film->ySize;

	for (int j = ny-1; j >= 0 ; j--){
		for(int i = 0; i <  nx; i++){
			float u = float(i) / float (nx);
			float v = float(j) / float (ny);
				
			float current_z;

			SurfaceInteraction surfaceInteraction;

			ray r = cam->traceRay(u,v);

			if( scene.intersect(r, MINSIGHT, MAXSIGHT, surfaceInteraction) ){
				current_z = surfaceInteraction.time;

				if(current_z < zMin) zMin = current_z;
				if(current_z > zMax) zMax = current_z;

			}			
		}
	}

}


/*
Flat_integrator::Flat_integrator(std::shared_ptr<Camera> camera):Sample_integrator(camera){}

Color Flat_integrator::Li( ray& r, Scene& scene){
	SurfaceInteraction surfaceInteraction;

	if(scene.intersect(r,MINSIGHT,MAXSIGHT, surfaceInteraction)){
		return surfaceInteraction.primitive->material->color;
	}

	return scene.sampleBG(r);
}

*/