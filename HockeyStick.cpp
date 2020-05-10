#include "HockeyStick.h"

HockeyStick::HockeyStick(double hit_time, int gate, bool accelerate){
	this->hit_time = hit_time;
	this->gate = gate;
	this->accelerate = accelerate;
}