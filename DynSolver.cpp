#include "DynSolver.h"
#define GRAVITY 9.81
#define GRAVITY 9.81
#define HOCKEY_PUCK_MASS 0.1

vector<vector<double>> DynSolver::explicit_euler_solver(vector<vector<double>> &current_state, double current_time, double dt){
	/*
		|coord_n+1| = |1 dt  0| |coord_n|
		|  V_n+1  | = |0  1 dt|*|  V_n  |
								|  a_n  |
	*/
	vector<vector<double>> new_state;
	vector<double> acc = calculate_acceleration(current_state, current_time);
	int index = 0;
	for(vector<double> &single_dim_state: current_state){
		vector<double> new_dim_state;
		new_dim_state.push_back(single_dim_state[0] + single_dim_state[1]*dt);
		new_dim_state.push_back(single_dim_state[1] + acc[index]*dt);
		new_state.push_back(new_dim_state);
		index++;
	}
	return new_state;
}

vector<vector<double>> DynSolver::symplectic_euler_solver(vector<vector<double>> &current_state, double current_time, double dt){
	/*
		|coord_n+1| = |1 dt dt^2| |coord_n|
		|  V_n+1  | = |0  1   dt|*|  V_n  |
								  |  a_n  |
	*/
	vector<vector<double>> new_state;
	vector<double> acc = calculate_acceleration(current_state, current_time);
	int index = 0;
	for(vector<double> &single_dim_state: current_state){
		vector<double> new_dim_state;
		new_dim_state.push_back(single_dim_state[0] + single_dim_state[1]*dt + acc[index]*dt*dt);
		new_dim_state.push_back(single_dim_state[1] + acc[index]*dt);
		new_state.push_back(new_dim_state);
		index++;
	}
	return new_state;
}

vector<vector<double>> DynSolver::runge_kutta_second_order_solver(vector<vector<double>> &current_state, double current_time, double dt){
	// http://stratum.ac.ru/education/textbooks/modelir/lection15.html alfa=1
	vector<vector<double>> new_state;
	new_state = explicit_euler_solver(&current_state, current_time, dt/2);
	vector<double> acc = calculate_acceleration(&new_state, current_time + dt/2);

	int index = 0;
	for(vector<double> &single_dim_state: current_state){
		vector<double> new_dim_state;
		new_dim_state.push_back(single_dim_state[0] + single_dim_state[1]*dt);
		new_dim_state.push_back(single_dim_state[1] + acc[index]*dt);
		new_state.push_back(new_dim_state);
		index++;
	}

	return new_state;
}


vector<double> DynSolver::calculate_acceleration(vector<vector<double>> &current_state, double current_time){
	double velocity_squared, velocity;
	vector<double> acceleration_components;
	for(vector<double> &single_dim_state: current_state){
		velocity_squared = pow(single_dim_state[1],2);
	}
	velocity = pow(velocity_squared, 0.5);

	double cos, acc_comp;
	for(vector<double> &single_dim_state: current_state){
		cos = single_dim_state[1] / velocity;
		acc_comp = HOCKEY_PUCK_MASS * GRAVITY * friction_coeff * cos;
		acceleration_components.push_back(acc_comp);
	}

	return acceleration_components;
}

double DynSolver::friction_coeff = 0.1;

