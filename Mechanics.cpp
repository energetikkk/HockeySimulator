#include "Mechanics.h"

void Mechanics::process_border_collision(HockeyPuck *hockeyPuck, IceRink *iceRink){
	std::pair<double, double> coords = hockeyPuck->get_position();
	std::pair<double, double> velocity = hockeyPuck->get_velocity();
	if ( (coords.first > iceRink->x_size) || (coords.first < 0) ){
		coords.first = coords.first < 0 ? 0 : iceRink->x_size;
		velocity.first = velocity.first*(-1);
	}
	if ( (coords.second > iceRink->y_size) || (coords.second < 0) ){
		coords.second = coords.second < 0 ? 0 : iceRink->y_size;
		velocity.second = velocity.second*(-1);
	}
	hockeyPuck->set_position(coords.first, coords.second);
	hockeyPuck->set_velocity(velocity.first, velocity.second);
}

std::pair<double, double> Mechanics::get_velocity_parts(HockeyPuck *hockeyPuck, IceRink *iceRink, int gate){

	std::pair<double, double> coords = hockeyPuck->get_position();
	double x_h = coords.first;
	double y_h = coords.second;
	double x_g = iceRink->gates[gate].x_coord;
	double y_g = iceRink->gates[gate].y_coord;
	double delta_x = x_g - x_h;
	double delta_y = y_g - y_h;
	double dist = pow( pow(delta_x, 2) + pow(delta_y, 2), 0.5);
	double cos = delta_x / dist;
	double sin = delta_y / dist;

	return  pair<double, double>(cos, sin);
}

bool Mechanics::is_goal(HockeyPuck *hockeyPuck, IceRink *iceRink){
	bool is_goal;
	pair<double, double> coords = hockeyPuck->get_position();

	for(int i = 0; i < 2; i++){
		auto gate = iceRink->gates[i];
		if( (coords.first < gate.x_coord + gate.width/2) && (coords.first > gate.x_coord - gate.width/2)
			&& (coords.second < gate.y_coord + gate.height/2) && (coords.second > gate.y_coord - gate.width/2) ){
            is_goal = true;
		}
	}
	return is_goal;
}
