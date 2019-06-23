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
#include "integrator.h"
#include "sample_integrator.h"
#include "flat_integrator.h"
#include "depth_integrator.h"
#include "normal_integrator.h"


using json::JSON;
typedef vec3 Color;
typedef vec3 Point;

std::vector< shared_ptr<Material> > material_list;

shared_ptr<Camera> cam;
shared_ptr<Primitive_list> world;
shared_ptr<Background> background;

shared_ptr<Scene> scene;

shared_ptr<Integrator> integrator;

//instantiates every element needed to generate image
void init_engine(){
	//turns the file into JSON obj (interpretable by code)
	JSON obj = parseFile("./jsonInput/scene.json");

	//makes material list, camera, world, scene, background, pixel buffer, materials and integrator from obj
	material_list = materialsFromJSON(obj);

	cam = cameraFromJSON(obj);
	world = primitivesFromJSON(obj,material_list);

	background = backgroundFromJSON(obj);
	cam->film = plotterFromJSON(obj);

	scene = make_shared<Scene>(world, cam ,background);

	integrator = integratorFromJSON(obj, cam);
}


int main(){

	init_engine();
	//renders the image
	integrator->render(*scene);
}