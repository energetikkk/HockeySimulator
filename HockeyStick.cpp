#include "HockeyStick.h"

HockeyStick::HockeyStick(int x_coord , int y_coord, int angle, bool accelerate, int hit_time){
	this->x_coord = x_coord;
	this->y_coord = y_coord;
	this->angle = angle;
	this->accelerate = accelerate;
	this->hit_time = hit_time;
}