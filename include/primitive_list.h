#ifndef PRIMITIVELISTH
#define PRIMITIVELISTH

#include <iostream>
#include <vector>
#include "primitive.h"

using namespace std;

class Primitive_list: public Primitive{
public:
	//structured list of primitives (shapes)
	Primitive** list;
	int list_size;

	Primitive_list();

	Primitive_list(Primitive**, int);
	//check if ray hits anything inside
	bool intersect(const ray&, float, float, SurfaceInteraction&);
	//check, but store no info about interaction
	bool intersect_p(const ray&, float, float);
};

#endif