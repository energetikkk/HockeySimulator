class Simulator{
	double delta_t = 0.01;
	boolean stick_hit = false;
	Stick *active_stick;
	boolean is_running = false;
	public:
	void start_experiment();
	void pause_experiment();
	void reset_experiment();
	private:
	void init_experiment();
	void validate_sticl_quee();
	void iteration();
};

void start_experiment(){
	this.is_running = true;
	while(this.is_running){
		//Simulate
	}
}

void pause_experiment(){
	this.is_running = false;
}

void reset_experiment(){
	this.is_running = false;
	init_experiment();
}

void init_experiment(){
}

void validate_sticl_quee(){
}

void iteration(){
}
