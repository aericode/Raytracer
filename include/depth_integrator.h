#ifndef DEPTHINTEGRATORH
#define DEPTHINTEGRATORH

#include <memory>
#include "sample_integrator.h"
#include "integrator.h"
#include "camera.h"
#include "scene.h"

typedef vec3 Color;

class Depth_integrator : public Sample_integrator {
public:
	//colors to be interpolated considering distance from the camera
	Color near_color;
	Color far_color;

	//closest and most distant point from the camera
	float zMin;
	float zMax;

	//gets the closest and the farmost point from the camera in the scene
	void preprocess ( Scene& );

	//initializes receiving a camera and the near and far color to interpolate
    Depth_integrator ( std::shared_ptr<Camera>, Color, Color );

    //Gets which color a certain point in the picture should have
    Color Li( ray&, Scene&);
};

#endif