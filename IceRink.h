#pragma once
#include <vector>

using namespace std;

class IceRink{
	public:
		int x_size, y_size;
		IceRink(double x_size, double y_size);
		struct Gate{
			double x_coord, y_coord, width, height;
			Gate(double x_coord, double y_coord, double width, double height);
		};
		vector<Gate> gates;
		class Border{
			double a1, a2, a3, x1, y1, x2, y2;
			public:
				Border(double a1, double a2, double a3, double x1, double y1, double x2, double y2);
		};
		vector<Border> borders;

};
