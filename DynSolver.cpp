#include "DynSolver.h"
#include <iostream>
#define GRAVITY 9.81
#define GRAVITY 9.81
#define HOCKEY_PUCK_MASS 0.1
#define DIMS 2
#define NUM_OF_VARS 2

double** DynSolver::explicit_euler_solver(double **current_state, double current_time, double dt){
	/*
		|coord_n+1| = |1 dt  0| |coord_n|
		|  V_n+1  | = |0  1 dt|*|  V_n  |
								|  a_n  |
	*/
	double** new_state = new double*[2];
	double *acc = calculate_acceleration(current_state, current_time);
	for(int i = 0; i < DIMS; i++){
		new_state[i] = new double[2];
		new_state[i][0] = current_state[i][0] + current_state[i][1]*dt;
		new_state[i][1] = current_state[i][1] + acc[i]*dt;
	}

	return new_state;
}

double** DynSolver::symplectic_euler_solver(double **current_state, double current_time, double dt){
	/*
		|coord_n+1| = |1 dt dt^2| |coord_n|
		|  V_n+1  | = |0  1   dt|*|  V_n  |
								  |  a_n  |
	*/
	double** new_state = new double*[DIMS];
	double *acc = calculate_acceleration(current_state, current_time);
	for(int i = 0; i < DIMS; i++){
		new_state[i] = new double[NUM_OF_VARS];
		new_state[i][0] = current_state[i][0] + current_state[i][1]*dt + acc[i]*dt*dt;
		new_state[i][1] = current_state[i][1] + acc[i]*dt;
	}
	return new_state;
}

double** DynSolver::runge_kutta_second_order_solver(double** current_state, double current_time, double dt){
	// http://stratum.ac.ru/education/textbooks/modelir/lection15.html alfa=1
	double** new_state = new double*[DIMS];
	new_state = explicit_euler_solver(current_state, current_time, dt/2);
	double *acc = calculate_acceleration(new_state, current_time + dt/2);

	for(int i = 0; i < DIMS; i++){
		new_state[i] = new double[NUM_OF_VARS];
		new_state[i][0] = current_state[i][0] + current_state[i][1]*dt;
		new_state[i][1] = current_state[i][1] + acc[i]*dt;
	}

	return new_state;
}

double* DynSolver::calculate_acceleration(double** current_state, double current_time){
	double velocity_squared, velocity;
	double* acceleration_components = new double[DIMS];
	for(int i = 0; i < DIMS; i++){
		velocity_squared = pow(current_state[i][1],2);
	}
	velocity = pow(velocity_squared, 0.5);

	double cos, acc_comp;
	for(int i = 0; i < DIMS; i++){
		cos = current_state[i][1] / velocity;
		acc_comp = -1 * HOCKEY_PUCK_MASS * GRAVITY * friction_coeff * cos;
		acceleration_components[i] = acc_comp;
	}

	return acceleration_components;
}

double DynSolver::friction_coeff = 0.1;

