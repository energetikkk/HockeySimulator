#pragma once
#include <vector>
#include <vcl.h>

using namespace std;

class HockeyPuck{
	public:
		double friction_coeff;
		vector<vector<double>> current_state;

		std::pair<double, double> get_position();
		std::pair<double, double> get_velocity();
		void set_position(double x, double y);
		void set_velocity(double v_x, double v_y);
		vector<vector<double>> get_current_state();
		void set_current_state(vector<vector<double>> new_state);
		HockeyPuck(double x, double y);
	private:
		void recalculate_acceleration();
};
