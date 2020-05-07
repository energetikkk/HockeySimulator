#pragma once
#include "HockeyPuck.h"
#include "IceRink.h"

class Mechanics{
	public:
		static void check_border_collision(HockeyPuck *hockeyPuck, IceRink *iceRink);
		static void check_stick_hit();
	private:
		static double calculate_puck_angle();
		static double calculate_stick_angle();
};
