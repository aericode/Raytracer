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

int main(){


	
	JSON obj = parseFile("./jsonInput/scene.json");

	material_list = materialsFromJSON(obj);


	cam = cameraFromJSON(obj);
	world = primitivesFromJSON(obj,material_list);

	background = make_shared<Background>();

	scene = make_shared<Scene>(world, cam ,background);

	int nx = 200;
	int ny = 100;

	Plotter plotter(nx,ny,"./imageOutput/default.ppm");
	cam->film = plotter;


	for (int j = ny-1; j >= 0 ; j--){
		for(int i = 0; i <  nx; i++){
			float u = float(i) / float (nx);
			float v = float(j) / float (ny);
			
			ray r = cam->traceRay(u,v);

			//Col recebe a cor do que o raio atinge
			Color col = cam->flatColor(r, scene);

			int ir  = int(255.99*col[0]);
			int ig  = int(255.99*col[1]);
			int ib  = int(255.99*col[2]);

			cam->changePixel(i,j, Color(ir,ig,ib));
			
		}
	}

	cam->plotFile();
	
}