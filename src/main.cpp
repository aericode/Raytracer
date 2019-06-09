#include <iostream>
#include <fstream>
#include <memory>

#include "json.hpp"
#include "jsonReader.h"
#include "perspective_camera.h"
#include "orthogonal_camera.h"
#include "camera.h"
#include "ray.h"
#include "sphere.h"
#include "plotter.h"
#include "primitive_list.h"


using json::JSON;
typedef vec3 Color;
typedef vec3 Point;

std::vector< shared_ptr<Material> > material_list;

shared_ptr<Camera> cam;
shared_ptr<Primitive_list> world;
shared_ptr<Background> background;

shared_ptr<Scene> scene;

void init_engine(){
	JSON obj = parseFile("./jsonInput/scene.json");

	material_list = materialsFromJSON(obj);

	cam = cameraFromJSON(obj);
	world = primitivesFromJSON(obj,material_list);

	background = backgroundFromJSON(obj);
	cam->film = plotterFromJSON(obj);

	scene = make_shared<Scene>(world, cam ,background);
}


int main(){

	init_engine();
	

	int nx = scene->camera->film->xSize;
	int ny = scene->camera->film->ySize;

	for (int j = ny-1; j >= 0 ; j--){
		for(int i = 0; i <  nx; i++){
			float u = float(i) / float (nx);
			float v = float(j) / float (ny);
			
			ray r = cam->traceRay(u,v);

			//Col recebe a cor do que o raio atinge
			Color col = cam->flatColor(r, scene);

			cam->changePixel(i,j,col);
			
		}
	}

	cam->plotFile();
	
}