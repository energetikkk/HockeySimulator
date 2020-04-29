#pragma once

class IceRink{
	public:
		int x_size, y_size;
		IceRink(int x_size, int y_size);
	private:
		struct Gate{
			int x_coord, y_coord, width, height;
			Gate(int x_coord, int y_coord, int width, int height);
		};
		Gate gates[];

};
