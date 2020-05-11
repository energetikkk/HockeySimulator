#pragma once
#include "IceRink.h"
#include "HockeyPuck.h"
#include "HockeyStick.h"
#include <vector>
#include <deque>

using namespace std;

class Simulator{
	public:
		double dt, stick_hit_angle;
		int solver_method;
		bool is_stick_hit;
		bool enough_energy();
		bool is_goal();
		vector<vector<double>> *current_state;
		vector<vector<double>> *updated_state;
		void reset_experiment();
		void do_one_step();
		void set_hockey_puck_speed(double speed, double angle);
		void set_friction_coeff(double coeff);
		void set_dt(double dt);
		void add_stick(double delta_t, int gate, bool accelerate);
		double get_current_time();
		std::pair<double,double> get_stick_hit_info();
		std::pair<double, double> get_hockey_puck_position();
		std::pair<double, double> get_hockey_puck_speed();
        vector<vector<UnicodeString>> get_stick_quee();
		Simulator(double ice_rink_length, double ice_rink_width);

	private:
		double current_time;
		deque<HockeyStick> stick_quee;
		IceRink *iceRink;
		HockeyPuck *hockeyPuck;
		void validate_stick_quee();
		void init_experiment();
		bool stick_comparator();

};
