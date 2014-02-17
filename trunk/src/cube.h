#pragma once

#include "vector.h"

class Cube {
	public:
	Vector pos;
	double size;
	Cube();
	Cube(double cntrx, double cntry, double cntrz, double scale);
	Cube(Vector place, double scale);
	private:
	void gen_arrays();
	Vector verts[8];
	static const int faces[6][4]; 
};
