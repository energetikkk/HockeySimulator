#pragma once
#include "IceRink.h"

class Simulator{
	public:
		double current_time;
		double delta_t;

		void init_experiment();
		void start_experiment();
		void pause_experiment();
		void reset_experiment();
		Simulator();
	private:
		boolean stick_hit;
		boolean is_running;
		//Stick *active_stick;
		IceRink *iceRink;

		void validate_stick_quee();
		void iteration();
};
