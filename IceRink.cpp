#include "IceRink.h"

#define GATE_WIDTH 1
#define GATE_HEIGHT 1
#define GATE_MARGIN 2

IceRink::IceRink(double x_size , double y_size){
	this->x_size = x_size;
	this->y_size = y_size;
	gates[0] =  Gate(GATE_MARGIN, y_size/2, GATE_WIDTH, GATE_HEIGHT);
	gates[1] =  Gate(x_size - GATE_MARGIN, y_size/2, GATE_WIDTH, GATE_HEIGHT);
}

IceRink::Gate::Gate(double x_coord, double y_coord, double width, double height):
	x_coord(x_coord), y_coord(y_coord), width(width), height(height){}
