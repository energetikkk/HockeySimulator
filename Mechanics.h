#pragma once

class Mechanics{
	public:
		static double friction_coeff;

		static void check_border_collision();
		static void check_stick_hit();
	private:
		double barrier_angle;

		static int calculate_puck_angle(double barrier_angle);
		static int calculate_stick_angle();
};
