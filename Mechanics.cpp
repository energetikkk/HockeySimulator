#include "Mechanics.h"

void Mechanics::border_collision_actions(HockeyPuck *hockeyPuck, IceRink *iceRink){
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

void Mechanics::stick_hit_actions(HockeyPuck *hockeyPuck, IceRink *iceRink){

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
