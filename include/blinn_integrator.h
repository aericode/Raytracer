#ifndef BLINNH
#define BLINNH

#include <memory>
#include "sample_integrator.h"
#include "camera.h"
#include "ray.h"
#include "scene.h"

typedef vec3 Color;

class Blinn_integrator : public Sample_integrator {
public:

    Blinn_integrator ( std::shared_ptr<Camera> );
    //assign's a color based on each collision point's normal
    Color Li( ray&, Scene&);
};


#endif