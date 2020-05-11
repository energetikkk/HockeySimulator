#pragma once
#include <vector>

using namespace std;

class DynSolver{
	public:
		static double friction_coeff;
        static double** integration_step(double **current_state, double current_time, double dt, int solver_method);
		static double** explicit_euler_solver(double **current_state, double current_time, double dt);
		static double** symplectic_euler_solver(double **current_state, double current_time, double dt);
		static double** runge_kutta_second_order_solver(double **current_state, double current_time, double dt);
    private:
		static double* calculate_acceleration(double **current_state, double current_time);
};
