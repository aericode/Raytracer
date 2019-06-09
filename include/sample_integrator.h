#ifndef SAMPLEINTEGRATORH
#define SAMPLEINTEGRATORH

#include <memory>
#include <>

typedef vec3 Color;

class SampleIntegrator : public Integrator {
//=== Public interface
protected:
    std::shared_ptr<Camera> camera;
public:
    virtual ~SampleIntegrator();
    SampleIntegrator( std::shared_ptr<Camera> cam);

    virtual Color Li( const ray& r, const Scene& scene) const = 0;
    virtual void render( const Scene& scene );
    virtual void preprocess( const Scene& scene );
};

#endif