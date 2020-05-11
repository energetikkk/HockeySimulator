#pragma once
#include "HockeyPuck.h"
#include "IceRink.h"
#include "HockeyStick.h"

class Mechanics{
	public:
		static void process_border_collision(HockeyPuck *hockeyPuck, IceRink *iceRink);
		static std::pair<double, double> get_velocity_parts(HockeyPuck *hockeyPuck, IceRink *iceRink, int gate);
        static bool is_goal(HockeyPuck *hockeyPuck, IceRink *iceRink);
};
