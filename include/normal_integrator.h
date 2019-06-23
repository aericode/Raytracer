#ifndef NORMALINTEGRATORH
#define NORMALINTEGRATORH

#include <memory>
#include "sample_integrator.h"
#include "integrator.h"
#include "camera.h"
#include "scene.h"

typedef vec3 Color;

class Normal_integrator : public Sample_integrator {
public:

    Normal_integrator ( std::shared_ptr<Camera> );
    //assign's a color based on each collision point's normal
    Color Li( ray&, Scene&);
};

#endif