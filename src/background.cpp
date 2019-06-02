#include "background.h"
#include "ray.h"
#include "vec3.h"

typedef vec3 Color;

Background::Background(){}

Color Background::sample(const ray& r){
	//vetor unitario
	vec3 unit_direction = unit_vector(r.direction());

	//metade do Y do vetor unitário + 1 
	float t = 0.5*(unit_direction.y() + 1.0);

	//aumenta e diminui em funcao deste valor do (branco total ao azul)
	return (1.0-t)*Color(1.0,1.0,1.0) + t*Color(0.5,0.7,1.0);
}