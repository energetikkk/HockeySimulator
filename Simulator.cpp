#include "Simulator.h"

Simulator::Simulator(){
	init_experiment();
}

void Simulator::start_experiment(){
	is_running = true;
	while(is_running){
		iteration();
	}
}

void Simulator::pause_experiment(){
	is_running = false;
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
