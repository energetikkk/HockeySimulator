#pragma once

class HockeyPack{
	public:

		int pos_x;
		int pos_Y ;
		double angle;
		double velocity;
		double friction_coeff;
		void move(double delta_t);
		void accelerate(double acceleration_ratio);
        void change_direction(double new_angle);
		HockeyPack();

	private:
    void change_direction(double new_angle);
};
