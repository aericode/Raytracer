#ifndef FLATINTEGRATORH
#define FLATINTEGRATORH

#include <memory>
#include "sample_integrator.h"
#include "integrator.h"
#include "camera.h"
#include "scene.h"

typedef vec3 Color;

class Flat_integrator : public Sample_integrator {
public:

    Flat_integrator ( std::shared_ptr<Camera> );

    Color Li( ray&, Scene&);
};

#endif