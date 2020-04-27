#include <vcl.h>
#include "IceRink.h"

IceRink::IceRink(){
	x_size = 630;
	y_size = 280;
//	gates[0] =  Gate(10,10,10,10);
//	gates[1] =  Gate(10,10,10,10);
}
IceRink::Gate(int gate_x, int gate_y, int width, int height):
	gate_x(gate_x), gate_y(gate_y), width(width), height(height){}

