#include <vcl.h>
#include "Simulator.h"
#include "IceRink.h"
#include "Mechanics.h"
#include <math.h>
#include "DynSolver.h"
#include <algorithm>
#include <string>

#define PI 3.14159265

using namespace std;

Simulator::Simulator(double ice_rink_length, double ice_rink_width){
	iceRink = new IceRink(ice_rink_length, ice_rink_width);
	hockeyPuck = new HockeyPuck();
	init_experiment();
}

void Simulator::reset_experiment(){
	init_experiment();
}

void Simulator::init_experiment(){
	current_time = 0.0;
	stick_hit = false;
	hockeyPuck->set_position((iceRink->x_size)/2, (iceRink->y_size)/2);
	hockeyPuck->set_velocity(0, 0);
	stick_quee.clear();
}

void Simulator::validate_stick_quee(){
	// To be implemented
}

void Simulator::do_one_step(){

	Mechanics::border_collision_actions(hockeyPuck, iceRink);


	double** new_state;
	double** current_state = hockeyPuck->get_current_state();

	switch(solver_method) {
		case 0:
			new_state = DynSolver::explicit_euler_solver(current_state, current_time, dt);
			break;
		case 1:
			new_state = DynSolver::symplectic_euler_solver(current_state, current_time, dt);
			break;
		case 2:
			new_state = DynSolver::runge_kutta_second_order_solver(current_state, current_time, dt);
			break;
		default:
            exit(1);
	}
	hockeyPuck->set_current_state(new_state);
	current_time += dt;
}

void Simulator::set_hockey_puck_speed(double speed, double angle){
	double v_x = speed*cos(angle*PI/180);
	double v_y = speed*sin(angle*PI/180);
	hockeyPuck->set_velocity(v_x, v_y);
}

void Simulator::set_friction_coeff(double coeff){
	DynSolver::friction_coeff = coeff;
}

std::pair<double, double> Simulator::get_hockey_puck_position(){
	return hockeyPuck->get_position();
}

std::pair<double, double> Simulator::get_hockey_puck_speed(){
	return hockeyPuck->get_velocity();
}

double Simulator::get_current_time(){
	return current_time;
}

bool Simulator::enough_energy(){
	return hockeyPuck->get_speed() > 0.05;
}

void Simulator::set_dt(double dt){
	this->dt = dt;
}

void Simulator::add_stick(double delta_t, int gate, bool accelerate){
	double hit_time = current_time + delta_t;

	for(auto stick: stick_quee){
		if(hit_time == stick.hit_time){
			throw "Hockey stick with such hit time exists!";
		}
	}
	stick_quee.push_back(HockeyStick(hit_time, gate, accelerate));
	sort(stick_quee.begin(), stick_quee.end(), [](auto& hSt1, auto& hSt2){
		return hSt1.hit_time < hSt2.hit_time;
	});
}

vector<vector<UnicodeString>> Simulator::get_stick_quee(){
	vector<vector<UnicodeString>> stringified_stick_quee;
	for(HockeyStick stick: stick_quee){
		vector<UnicodeString> stringified_stick;
		stringified_stick.push_back(FloatToStr(stick.hit_time));
		stringified_stick.push_back(IntToStr(stick.gate));
		stringified_stick.push_back(stick.accelerate);
		stringified_stick_quee.push_back(stringified_stick);
	}
	return stringified_stick_quee;
}

bool Simulator::is_goal(){
	return Mechanics::is_goal(hockeyPuck, iceRink);
}

