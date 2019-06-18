#include "sample_integrator.h"
#include "camera.h"
#include "scene.h"
#include "vec3.h"

typedef vec3 Color;

Sample_integrator::Sample_integrator( std::shared_ptr<Camera> camera){
	cam = camera;
}


void Sample_integrator::render( Scene& scene){

	preprocess(scene);


	int nx = scene.camera->film->xSize;
	int ny = scene.camera->film->ySize;

	for (int j = ny-1; j >= 0 ; j--){
		for(int i = 0; i <  nx; i++){
			float u = float(i) / float (nx);
			float v = float(j) / float (ny);
			
			ray r = cam->traceRay(u,v);

			//Col recebe a cor do que o raio atinge
			Color col = Li(r, scene);

			cam->changePixel(i,j,col);
			
		}
	}

	cam->plotFile();
}