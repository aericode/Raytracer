#define cor00 interpolate[0]
#define cor01 interpolate[1]
#define cor10 interpolate[2]
#define cor11 interpolate[3]

#include "background.h"
#include "ray.h"
#include "vec3.h"

typedef vec3 Color;

Background::Background(){
	
}

Background::Background(Color colors[4]){
	for(int i =0; i < 4; i++){
		interpolate[i] = colors[i];
	}
}


/*
Color Background::sample(const ray& r){
	//vetor unitario
	vec3 unit_direction = unit_vector(r.direction());

	//metade do Y do vetor unitário + 1 
	float t = 0.5*(unit_direction.y() + 1.0);

	//aumenta e diminui em funcao deste valor do (branco total ao azul)
	return (1.0-t)*Color(1.0,1.0,1.0) + t*Color(0.5,0.7,1.0);
}
*/

//Color interpolatePixel(float tx, float ty, Color cor00, Color cor10, Color cor01, Color cor11){
Color Background::sample(const ray& r){
	vec3 unit_direction = unit_vector(r.direction());

	float tx = 0.5*(unit_direction.x() + 1.0);
	float ty = 0.5*(unit_direction.y() + 1.0);

	Color left  = cor00 * (1 - tx) + cor10 * tx;
	Color right = cor01 * (1 - tx) + cor11 * tx;

	Color interpolated = left * (1 - ty) + right * ty;
	interpolated[0] = (int)interpolated[0];
	interpolated[1] = (int)interpolated[1];
	interpolated[2] = (int)interpolated[2];

	return interpolated;
}
