#ifndef INTEGRATORH
#define INTEGRATORH

#include "scene.h"

class Integrator{
public:
    virtual ~Integrator();
    virtual void render( const Scene& scene ) =0;
};


#endif