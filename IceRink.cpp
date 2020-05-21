#include "IceRink.h"
#include <limits>

#define GATE_WIDTH 1
#define GATE_HEIGHT 2
#define GATE_MARGIN 5

IceRink::IceRink(double x_size , double y_size){
	this->x_size = x_size;
	this->y_size = y_size;
	gates.push_back(Gate(GATE_MARGIN, y_size/2, GATE_WIDTH, GATE_HEIGHT));
	gates.push_back(Gate(x_size - GATE_MARGIN, y_size/2, GATE_WIDTH, GATE_HEIGHT));
	// Horizontal borders
	borders.push_back(Border(0,0,0,8,0,55,0));
	borders.push_back(Border(0,0,23,8,0,55,23));
	// Vertical borders
	borders.push_back(Border(0,numeric_limits<double>::max(),0,0,7,0,16));
	borders.push_back(Border(0,numeric_limits<double>::max(),0,63,7,63,16));
	// Angles as polynomials of 2-nd order
    // It isn't worth my efforts to implement flexible enough border reflection logic

}

IceRink::Gate::Gate(double x_coord, double y_coord, double width, double height):
	x_coord(x_coord), y_coord(y_coord), width(width), height(height){}

IceRink::Border::Border(double a1, double a2, double a3, double x1, double y1, double x2, double y2):
    a1(a1), a2(a2), a3(a3), x1(x1), y1(y1), x2(x2), y2(y2){}

