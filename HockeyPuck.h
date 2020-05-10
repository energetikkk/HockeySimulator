#pragma once
#include <vector>
#include <vcl.h>

#define DIMS 2
#define NUM_OF_VARS 2

using namespace std;

class HockeyPuck{
	public:
		std::pair<double, double> get_position();
		std::pair<double, double> get_velocity();
		void set_position(double x, double y);
		void set_velocity(double v_x, double v_y);
		double** get_current_state();
		void set_current_state(double **new_state);
        double get_speed();
		HockeyPuck();
	private:
		double x, y, v_x, v_y;
		double **current_state;
};
