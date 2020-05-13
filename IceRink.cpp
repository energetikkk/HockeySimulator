#include "IceRink.h"

#define GATE_WIDTH 2
#define GATE_HEIGHT 4
#define GATE_MARGIN 5

IceRink::IceRink(double x_size , double y_size){
	this->x_size = x_size;
	this->y_size = y_size;
	gates.push_back(Gate(GATE_MARGIN, y_size/2, GATE_WIDTH, GATE_HEIGHT));
	gates.push_back(Gate(x_size - GATE_MARGIN, y_size/2, GATE_WIDTH, GATE_HEIGHT));
}

IceRink::Gate::Gate(double x_coord, double y_coord, double width, double height):
	x_coord(x_coord), y_coord(y_coord), width(width), height(height){}

