#include <vcl.h>
#include "Simulator.h"
#include "IceRink.h"
#include "Mechanics.h"
#include <math.h>

typedef std::pair<double, double> HockeyPuckCoords;

Simulator::Simulator(double ice_rink_length, double ice_rink_width){
	iceRink = new IceRink(ice_rink_length, ice_rink_width);
	hockeyPuck = new HockeyPuck(ice_rink_length/2, ice_rink_width/2);
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

void Simulator::integration_step(){
	Sleep(delta_t * 1000);
	current_time += delta_t;
}

void Simulator::set_hockey_puck_speed(double speed, double angle){
	hockeyPuck->v_x = speed*cos(angle/360*M_PI);
	hockeyPuck->v_y = speed*sin(angle/360*M_PI);
}

void Simulator::set_friction_coeff(double coeff){
	hockeyPuck->friction_coeff = coeff;
}

std::pair<double, double> Simulator::get_hockey_puck_position(){
	return HockeyPuckCoords(hockeyPuck->x, hockeyPuck->y);
}

