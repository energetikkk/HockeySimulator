#pragma once
#include "IceRink.h"
#include "HockeyPuck.h"
#include "HockeyStick.h"
#include <vector>

using namespace std;

class Simulator{
	public:
		double dt;
		int solver_method;
		vector<vector<double>> *current_state;
		vector<vector<double>> *updated_state;
		void reset_experiment();
		void do_one_step();
		void set_hockey_puck_speed(double speed, double angle);
		void set_friction_coeff(double coeff);
		void set_dt(double dt);
		void add_stick(double delta_t, int gate, bool accelerate);
		double get_current_time();
		bool enough_energy();
        bool is_goal();
		std::pair<double, double> get_hockey_puck_position();
		std::pair<double, double> get_hockey_puck_speed();
        vector<vector<UnicodeString>> get_stick_quee();
		Simulator(double ice_rink_length, double ice_rink_width);

	private:
		bool stick_hit;
		double current_time;
		vector<HockeyStick> stick_quee;
		IceRink *iceRink;
		HockeyPuck *hockeyPuck;
		void validate_stick_quee();
		void init_experiment();

};
