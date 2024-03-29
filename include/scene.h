#ifndef SCENEH
#define SCENEH

#include "camera.h"
#include "primitive_list.h"
#include "background.h"
#include "ray.h"
#include <memory>
#include "surfaceInteraction.h"
#include "vec3.h"
#include "light.h"

class Camera;


using namespace std;
typedef vec3 Color;

//stores scene, camera, background

class Scene{
private:
	shared_ptr<Primitive_list> world;
	shared_ptr<Background> background;
public:
	shared_ptr<Camera> camera;
	std::vector<Light> lights;

	Scene();
	Scene(shared_ptr<Primitive_list>, shared_ptr<Camera>, shared_ptr<Background>);
	//calls intersect from primitives stored inside it
	bool intersect( const ray&, float, float, SurfaceInteraction&);
	bool intersect_p( const ray&, float, float);
	//get the color of the background
	Color sampleBG(const ray&);


};

#endif