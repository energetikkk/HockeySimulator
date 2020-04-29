#pragma once
#include "IceRink.h"
#include "HockeyPuck.h"

class Simulator{
	public:
		double current_time;
		double delta_t;

		void init_experiment();
		void start_experiment();
		void pause_experiment();
		void reset_experiment();
		void set_hockey_puck_angle(int angle);
		void set_hockey_puck_speed(int speed);
		void set_friction_coeff(double coeff);
        std::pair<int, int> get_hockey_puck_position();
		Simulator(const int ice_rink_width, const int ice_rink_height);
	private:
		bool stick_hit;
		bool is_running;
		//Stick *active_stick;
		IceRink *iceRink;
        HockeyPuck *hockeyPuck;

		void validate_stick_quee();
		void iteration();
};
