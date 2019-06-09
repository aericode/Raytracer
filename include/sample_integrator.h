#ifndef SAMPLEINTEGRATORH
#define SAMPLEINTEGRATORH

#include <memory>
#include "integrator.h"
#include "camera.h"
#include "scene.h"

typedef vec3 Color;

class SampleIntegrator : public Integrator {
//=== Public interface
protected:
    std::shared_ptr<Camera> cam;
public:
    SampleIntegrator( std::shared_ptr<Camera> );

    virtual Color Li( const ray&, const Scene&) const = 0;
    virtual void render( const Scene& );
    virtual void preprocess( const Scene& );
};

#endif