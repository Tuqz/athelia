#pragma once 
#include "vector.h"
#include "plane.h"
#include <array>

class Cube { 
	public:
	Vector position;
	double size;
	std::array<Plane, 6> faces;
	Cube(Vector pos);
	Cube(Vector pos, double dim);
	Cube(Vector pos, Colour colour);
	Cube(Vector pos, double dim, Colour colour);
	
	private:
	void gen_faces(Colour colour);
};
