#pragma once

class IceRink{
	public:
		double x_size, y_size;
		IceRink(double x_size, double y_size);
		struct Gate{
			double x_coord, y_coord, width, height;
			Gate(double x_coord, double y_coord, double width, double height);
		};
		Gate gates[];
};
