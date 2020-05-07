#pragma once
#include <vector>

using namespace std;

class DynSolver{
	public:
		static double friction_coeff;
		vector<vector<double>> explicit_euler_solver(vector<vector<double>> &current_state, double current_time, double dt);
		vector<vector<double>> symplectic_euler_solver(vector<vector<double>> &current_state, double current_time, double dt);
		vector<vector<double>> runge_kutta_second_order__solver(vector<vector<double>> &current_state, double current_time, double dt);
    private:
		vector<double> calculate_acceleration(vector<vector<double>> &current_state, double current_time);
};
