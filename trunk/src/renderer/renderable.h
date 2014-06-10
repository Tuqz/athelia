#pragma once
#include "ray.h"
#include "colour.h"

class Renderable {
	public:
	bool light;
	Vector position;
	double size;
	Colour colour;
	Renderable(bool isLight, Colour col) : light(isLight), colour(col) {}
	virtual double intersect(Ray r) {
		return 0;
	};
	virtual Ray intersection(Vector collide, Ray r) {
		return r;
	};
};
