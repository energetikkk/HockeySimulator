#include "HockeyPuck.h"

#define DIMS 2
#define NUM_OF_VARS 2

using namespace std;

HockeyPuck::HockeyPuck(){
	current_state = new double*[DIMS];
	for(int i = 0; i < DIMS; i++){
	   current_state[i] = new double[NUM_OF_VARS];
	}
}

std::pair<double, double> HockeyPuck::get_position(){
	return pair<double,double>(x, y);
}

pair<double, double> HockeyPuck::get_velocity(){
	return pair<double, double>(v_x, v_y);
}

void HockeyPuck::set_position(double x, double y){
	this->x = x;
	this->y = y;
}

void HockeyPuck::set_velocity(double v_x, double v_y){
	this->v_x = v_x;
	this->v_y = v_y;
}

// [ [x, v_x, a_x], [y, v_y, a_y] ]
double** HockeyPuck::get_current_state(){
	current_state[0][0] = x;
	current_state[1][0] = y;
	current_state[0][1] = v_x;
	current_state[1][1] = v_y;
	return current_state;
}

void HockeyPuck::set_current_state(double **new_state){
	current_state = new_state;
	x = current_state[0][0];
	y = current_state[1][0];
	v_x = current_state[0][1];
	v_y = current_state[1][1];
}

double HockeyPuck::get_speed(){
	return sqrt(pow(v_x,2) + pow(v_y,2));
}
