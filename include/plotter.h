#ifndef PLOTTER
#define PLOTTER
#include <iostream>
#include <fstream>

#include "vec3.h"

#include <vector>
#include <string>

using namespace std;
typedef vec3 Color;

class Plotter
{
private:

	vector<Color> colorBuffer;
	string fileName;

public:
	int xSize;
	int ySize;
	
	Plotter();
	//initializes a pixel buffer with specific x,y size and on an specific file
	Plotter(int,int,string);

	~Plotter();
	//finds the line where a point in a matrix is supposed to be
	int matrixToLine(int, int);
	//checks if pixel is outside image's range
	bool isValidLocation(int, int);
	//changes the color of a pixel in the image
	void changePixel(int, int, Color);
	//sets each pixel to 255 255 255 (white)
	void clear();
	//turn pixels from the buffer into an image
	void plotFile();
};

#endif