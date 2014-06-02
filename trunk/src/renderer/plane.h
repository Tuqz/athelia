#pragma once
#include "vector.h"
#include "ray.h"
#include "colour.h"

class Plane {
	public:
	Vector position;
	Vector normal;
	Vector up;
	Vector lateral;
	double d;
	Colour colour;
	double width;
	double height;
	Plane();
	Plane(Vector pos, Vector norm, Vector u, double w, double h, Colour col, bool isLight);
	double collide(Ray ray);
	bool light;
};
