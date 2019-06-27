#include "ambient_light.h"
#include "vec3.h"

Ambient_light::Ambient_light(){};

Ambient_light::Ambient_light(Color color, float intensity ):Light(color,intensity,true){}

