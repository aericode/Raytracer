#ifndef INTEGRATORH
#define INTEGRATORH

#include "scene.h"

class Integrator{
public:
    virtual void render( const Scene& scene ) =0;
};


#endif