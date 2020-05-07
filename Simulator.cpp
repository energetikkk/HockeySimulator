#include <vcl.h>
#include "Simulator.h"
#include "IceRink.h"
#include "Mechanics.h"
#include <math.h>
#include "DynSolver.h"

using namespace std;

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
	current_time = 0.0;
	stick_hit = false;
	//active_stick = null;
	is_running = false;
}

void Simulator::validate_stick_quee(){
	// To be implemented
}

void Simulator::integration_step(){

	hockeyPuck->set_current_state(hockeyPuck->get_current_state());
	current_time += dt;
	Sleep(dt*1000);
}

void Simulator::set_hockey_puck_speed(double speed, double angle){
	hockeyPuck->set_velocity(speed*cos(angle/360*M_PI), speed*sin(angle/360*M_PI));
}

void Simulator::set_friction_coeff(double coeff){
	DynSolver::friction_coeff = coeff;
}

std::pair<double, double> Simulator::get_hockey_puck_position(){
	return hockeyPuck->get_position();
}

