#pragma once
#include "vector.h"
#include "ray.h"
#include "renderable.h"

class Plane : public Renderable {
	public:
	Vector normal, up, lateral;
	double d, width, height;
	Plane();
	Plane(Vector pos, Vector norm, Vector u, double w, double h, Colour col, bool isLight);
	double intersect(Ray r);
	Ray intersection(Vector collide, Ray r);
};
