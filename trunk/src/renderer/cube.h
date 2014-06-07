#pragma once 
#include "vector.h"
#include "plane.h"
#include "renderable.h"
#include "ray.h"
#include <array>

class Cube : public Renderable { 
	public:
	Vector position;
	std::array<Plane, 6> faces;
	Cube(Vector pos, bool light);
	Cube(Vector pos, double dim, bool light);
	Cube(Vector pos, Colour col, bool light);
	Cube(Vector pos, double dim, Colour col, bool light);
	double intersect(Ray r);
	Ray intersection(Vector collide, Ray r);
	
	private:
	void gen_faces();
};
