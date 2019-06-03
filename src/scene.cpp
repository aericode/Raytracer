#include "scene.h"


Scene::Scene(){}

Scene::Scene(shared_ptr<Primitive_list> world, shared_ptr<Background> background){
	this->world = world;
	this->background = background;

}

bool Scene::intersect_p(const ray& r, float t_min, float t_max){
	return world->intersect_p(r,t_min,t_max);
}

bool Scene::intersect(const ray& r, float t_min, float t_max, SurfaceInteraction& inter){
	return world->intersect(r,t_min,t_max,inter);
}

Color Scene::sampleBG(const ray& r){
	return background->sample(r);
}