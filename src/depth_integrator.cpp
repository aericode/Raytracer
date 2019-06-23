#define MINSIGHT 0
#define MAXSIGHT 100000

#include "depth_integrator.h"

#include "ray.h"
#include "scene.h"
#include "surfaceInteraction.h"
#include "material.h"
#include "vec3.h"


Depth_integrator::Depth_integrator(std::shared_ptr<Camera> camera, Color near_color, Color far_color):Sample_integrator(camera){
	this->near_color = near_color;
	this->far_color  = far_color;
}

void Depth_integrator::preprocess(Scene& scene){

	zMin = MAXSIGHT; //inicia como max para ser substituído por um menor
	zMax = MINSIGHT; //inicia como max para ser substituído por um maior

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
				current_z = surfaceInteraction.ray_t;
				if(current_z < zMin) zMin = current_z;
				if(current_z > zMax) zMax = current_z;

			}			
		}
	}
}

Color Depth_integrator::Li( ray& r, Scene& scene){
	SurfaceInteraction surfaceInteraction;

	if( scene.intersect(r, MINSIGHT, MAXSIGHT, surfaceInteraction) ){
		float current_z = surfaceInteraction.ray_t;

		float delta = (current_z - zMin)/(zMax - zMin);

		int r = near_color.r() + (far_color.r() - near_color.r()) * delta;
		int g = near_color.g() + (far_color.g() - near_color.g()) * delta;
		int b = near_color.b() + (far_color.b() - near_color.b()) * delta;

		return Color(r,g,b);
	}else{

		return far_color;
	}

}
