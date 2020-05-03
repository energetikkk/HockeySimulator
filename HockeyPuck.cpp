#include "HockeyPuck.h"

#define DIMENSIONS 2
#define NUMBER_OF_VARIABLES 3
#define GRAVITY 9.81

using namespace std;

HockeyPuck::HockeyPuck(double x, double y){
	current_state.resize(DIMENSIONS, vector<double>(NUMBER_OF_VARIABLES));
	set_position(x, y);
}

std::pair<double, double> HockeyPuck::get_position(){
	return pair<double,double>(current_state[0][0], current_state[1][0]);
}

pair<double, double> HockeyPuck::get_velocity(){
	return pair<double, double>(current_state[0][1], current_state[1][1]);
}

void HockeyPuck::set_position(double x, double y){
	current_state[0][0] = x;
	current_state[1][0] = y;
}

void HockeyPuck::set_velocity(double v_x, double v_y){
	current_state[0][1] = v_x;
	current_state[1][1] = v_y;
}

// [ [x, v_x, a_x], [y, v_y, a_y] ]
vector<vector<double>> HockeyPuck::get_current_state(){
	return current_state;
}

void HockeyPuck::get_current_state(vector<vector<double>> new_state){
	current_state = new_state;
}

void HockeyPuck::recalculate_acceleration(){
	double velocity = pow(pow(current_state[0][1],2) + pow(current_state[1][1],2), 0.5));
	double sin_val = current_state[1][1] / velocity;
	double cos_val = current_state[0][1] / velocity;
	current_state[0][3] = hockeyPuck_mass * GRAVITY * friction_coeff * friction_coeff * cos_val;
	current_state[1][3] = hockeyPuck_mass * GRAVITY * friction_coeff * friction_coeff * sin_val;
}
