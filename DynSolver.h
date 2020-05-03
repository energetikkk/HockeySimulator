#pragma once
#include <vector>

using namespace std;

class DynSolver{
	public:
		vector<vector<double>> explicit_euler_solver(vector<vector<double>> &current_state, double current_time);
		vector<vector<double>> improved_euler_solver(vector<vector<double>> &current_state, double current_time);
		vector<vector<double>> runge_kutta_solver(vector<vector<double>> &current_state, double current_time);
};
