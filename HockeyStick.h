#pragma once

class HockeyStick{
	public:
		int x_coord, y_coord, angle, hit_time;
		bool accelerate;
		HockeyStick(int x_coord, int y_coord, int angle, bool accelerate, int hit_time);
};
