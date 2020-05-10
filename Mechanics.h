#pragma once
#include "HockeyPuck.h"
#include "IceRink.h"
#include "HockeyStick.h"

class Mechanics{
	public:
		static void border_collision_actions(HockeyPuck *hockeyPuck, IceRink *iceRink);
		static void stick_hit_actions(HockeyPuck *hockeyPuck, IceRink *iceRink);
        static bool is_goal(HockeyPuck *hockeyPuck, IceRink *iceRink);
};
