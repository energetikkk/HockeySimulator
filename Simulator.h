#pragma once

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
		//Stick *active_stick;
		boolean is_running;

		void validate_stick_quee();
		void iteration();
};
