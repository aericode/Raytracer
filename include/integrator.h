#ifndef INTEGRATORH
#define INTEGRATORH

#include "scene.h"

class Integrator{
public:
    virtual void render( Scene& scene ) =0;
};


#endif