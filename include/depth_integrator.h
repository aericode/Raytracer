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
	float zMin;
	float zMax;

	std::vector<float> zBuffer;

	void preprocess( Scene& );

    Depth_integrator ( std::shared_ptr<Camera> );

    Color Li( ray&, Scene&);
};

#endif