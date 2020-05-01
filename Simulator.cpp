#include <vcl.h>
#include "Simulator.h"
#include "IceRink.h"
#include "Mechanics.h"

typedef std::pair<int, int> HockeyPuckCoords;

Simulator::Simulator(const int ice_rink_width, const int ice_rink_height){
	iceRink = new IceRink(ice_rink_width, ice_rink_height);
	hockeyPuck = new HockeyPuck(ice_rink_width/2, ice_rink_height/2);
	init_experiment();
}

void Simulator::reset_experiment(){
	is_running = false;
	init_experiment();
}

void Simulator::init_experiment(){
	delta_t = 0.01; //in seconds
	current_time = 0.0;
	stick_hit = false;
	//active_stick = null;
	is_running = false;
}

void Simulator::validate_stick_quee(){
}

void Simulator::iteration(){
	Sleep(delta_t * 1000);
	current_time += delta_t;
}

void Simulator::set_hockey_puck_angle(int angle){
	hockeyPuck->angle = angle;
}

void Simulator::set_hockey_puck_speed(int speed){
	hockeyPuck->speed = speed;
}

void Simulator::set_friction_coeff(double coeff ){
	Mechanics::friction_coeff = coeff;
}

std::pair<int, int> Simulator::get_hockey_puck_position(){
	return HockeyPuckCoords(hockeyPuck->x_coord, hockeyPuck->y_coord);
}

