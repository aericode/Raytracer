#ifndef SAMPLEINTEGRATORH
#define SAMPLEINTEGRATORH

#include <memory>
#include "integrator.h"
#include "camera.h"
#include "scene.h"

typedef vec3 Color;

class Sample_integrator : public Integrator {
//=== Public interface
protected:
    std::shared_ptr<Camera> cam;
public:
    Sample_integrator( std::shared_ptr<Camera> );

    virtual Color Li( ray&, Scene&) = 0;
    void render( Scene& );
    void preprocess( Scene& );
};

#endif