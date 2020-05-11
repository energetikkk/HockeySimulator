#pragma once

class HockeyStick{
	public:
		double hit_time, angle;
		int gate;
		bool accelerate;
		HockeyStick(double hit_time, int gate, bool accelerate);
};
