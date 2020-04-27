#include <vcl.h>
#include "IceRink.h"

IceRink::IceRink(int x_size , int y_size){
	this->x_size = x_size;
	this->y_size = y_size;
	int x_coord = (x_size/2)/10;
	int y_coord = y_size/2;
	int width = x_size/20;
	int height = y_size/10;
	gates[0] =  Gate(x_coord, y_coord, width, height);
	gates[1] =  Gate(x_size - x_coord, y_coord, width, height);
}

IceRink::Gate::Gate(int x_coord, int y_coord, int width, int height):
	x_coord(x_coord), y_coord(y_coord), width(width), height(height){}
