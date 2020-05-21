#include "Mechanics.h"
#include <math.h>
#include <algorithm>

void Mechanics::process_border_collision(HockeyPuck *hockeyPuck, IceRink *iceRink, Simulator *simulator){
	std::pair<double, double> coords = hockeyPuck->get_position();
	std::pair<double, double> velocity = hockeyPuck->get_velocity();
	// Process arc angle hit
	double v_par,v_perp;
	double beta, res;
	if (simulator->get_current_time() - simulator->last_collision_time > 0.5){
		try{
			if(coords.first < 8.0 && coords.second < 8.0){
				if((pow(coords.first - 8.0,2.0) + pow(coords.second - 8.0, 2.0)) > 60.0){
					res = pow(64 - pow((coords.first>0?coords.first:0) - 8, 2), 0.5);
					coords.second = 8.0 - res;
					beta = 0.785;
					if (res != 0) {
						beta = atan((8.0 - coords.first)/res);
					}
					v_par = velocity.first * cos(beta) - velocity.second * sin(beta);
					v_perp = velocity.first * sin(beta) + velocity.second * cos(beta);
					velocity.first = v_par * cos(beta) + (-1.0) * v_perp * sin(beta);
					velocity.second = -1.0 * v_par * sin(beta) + (-1.0) * v_perp * cos(beta);
				}
			} else if (coords.first > 55 && coords.second < 8){
				if((pow(coords.first - 55.0,2.0) + pow(coords.second - 8, 2.0)) > 60.0){
					res = pow(64 - pow((coords.first<63?coords.first:63) - 55, 2), 0.5);
					coords.second = 8.0 - res;
					beta = 0.785;
					if (res != 0) {
						beta = atan((coords.first - 55.0)/res);
					}
					v_par = velocity.first * cos(beta) - velocity.second * sin(beta);
					v_perp = velocity.first * sin(beta) + velocity.second * cos(beta);
					velocity.first = v_par * cos(beta) + (-1.0) * v_perp * sin(beta);
					velocity.second = v_par * sin(beta) - (-1.0) * v_perp * cos(beta);
				}

			} else if (coords.first < 8 && coords.second > 20){
				if((pow(coords.first - 8.0,2.0) + pow(coords.second - 20, 2.0)) > 60.0){
					res = pow(64 - pow((coords.first>0?coords.first:0) - 8, 2), 0.5);
					coords.second = 20 + res;
					beta = 0.785;
					if (res != 0) {
						beta = atan((coords.first - 55.0)/res);
					}
					v_par = velocity.first * cos(beta) - velocity.second * sin(beta);
					v_perp = velocity.first * sin(beta) + velocity.second * cos(beta);
					velocity.first = v_par * cos(beta) + (-1.0) * v_perp * sin(beta);
					velocity.second = v_par * sin(beta) - (-1.0) * v_perp * cos(beta);
				}

			} else if (coords.first > 55 && coords.second > 20) {
				if((pow(coords.first - 55, 2) + pow(coords.second - 20, 2.0)) > 60){
					res = pow(64 - pow((coords.first<63?coords.first:63) - 55, 2), 0.5);
					coords.second = 20 + res;
					beta = 0.785;
					if (res != 0) {
						beta = atan((coords.first - 55)/res);
					}
					v_par = velocity.first * cos(beta) - velocity.second * sin(beta);
					v_perp = velocity.first * sin(beta) + velocity.second * cos(beta);
					velocity.first = v_par * cos(beta) + (-1.0) * v_perp * sin(beta);
					velocity.second = -1.0 * v_par * sin(beta) + (-1.0) * v_perp * cos(beta);
				}

		}
		} catch (...){
			exit(1);
		}
	}

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
	double x_g = (iceRink->gates)[gate].x_coord;
	double y_g = (iceRink->gates)[gate].y_coord;
	double delta_x = x_g - x_h;
	double delta_y = y_g - y_h;
	double dist = pow( pow(delta_x, 2) + pow(delta_y, 2), 0.5);
	double cos = delta_x / dist;
	double sin = delta_y / dist;

	return  pair<double, double>(cos, sin);
}

bool Mechanics::is_goal(HockeyPuck *hockeyPuck, IceRink *iceRink){
	bool is_goal = false;
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
