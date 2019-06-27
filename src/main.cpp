#include <iostream>
#include <fstream>
#include <memory>

#include "json.hpp"
#include "jsonReader.h"
#include "perspective_camera.h"
#include "orthogonal_camera.h"
#include "camera.h"
#include "vec3.h"
#include "ray.h"
#include "sphere.h"
#include "plotter.h"
#include "primitive_list.h"
#include "integrator.h"
#include "sample_integrator.h"
#include "flat_integrator.h"
#include "depth_integrator.h"
#include "normal_integrator.h"
#include "blinn_integrator.h"
#include "light.h"
#include "ambient_light.h"


using json::JSON;
typedef vec3 Color;
typedef vec3 Point;

std::vector< shared_ptr<Material> > material_list;

shared_ptr<Camera> cam;
shared_ptr<Primitive_list> world;
shared_ptr<Background> background;

shared_ptr<Scene> scene;

shared_ptr<Integrator> integrator;


//TODO integrate blinnmaterial with the jsonREADER
void add_blinn_material(){
	vec3 ka(0.4,0.4,0.4);
	vec3 kd(0.9,0.2,0.2);
	vec3 ks(255,255,255);

	shared_ptr<Material> to_add = make_shared<Material>("red",ka,kd,ks);
	material_list.push_back(to_add);
}

void add_lights(){
	vec3 color(255,0,0);
	float intensity = 0.1;
	Ambient_light ambient_light(color,intensity);

	scene->lights.push_back(ambient_light);
}

//instantiates every element needed to generate image
void init_engine(std::string filename){
	//turns the file into JSON obj (interpretable by code)
	JSON obj = parseFile(filename);

	//makes material list, camera, world, scene, background, pixel buffer, materials and integrator from obj
	//material_list = materialsFromJSON(obj);

	//using as substitute while not integrated with JSONreader
	add_blinn_material();

	cam = cameraFromJSON(obj);
	world = primitivesFromJSON(obj,material_list);

	background = backgroundFromJSON(obj);
	cam->film = plotterFromJSON(obj);

	scene = make_shared<Scene>(world, cam ,background);

	//integrator = integratorFromJSON(obj, cam);

	//using this while blynphong is not on jsonreader
	integrator = make_shared<Blinn_integrator>(cam);

	add_lights();
}


int main(){

	init_engine("./jsonInput/scene.json");
	//renders the image
	integrator->render(*scene);
}