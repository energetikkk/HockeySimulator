#pragma once
#include "IceRink.h"
#include "HockeyPuck.h"
#include "HockeyStick.h"
#include <vector>

using namespace std;

class Simulator{
	public:
		double current_time;
		double delta_t;
		vector<vector<double>> *current_state;
		vector<vector<double>> *updated_state;
		void init_experiment();
		void reset_experiment();
		void integration_step();
		void set_hockey_puck_speed(double speed, double angle);
		void set_friction_coeff(double coeff);
		std::pair<double, double> get_hockey_puck_position();
		Simulator(double ice_rink_length, double ice_rink_width);

	private:
		bool stick_hit;
		bool is_running;
		//HockeyStick *stick_quee[];
		IceRink *iceRink;
		HockeyPuck *hockeyPuck;

		void validate_stick_quee();

};
