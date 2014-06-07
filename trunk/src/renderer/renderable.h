#pragma once
#include "ray.h"
#include "colour.h"

class Renderable {
	public:
	bool light;
	Vector position;
	double size;
	Colour colour;
	Renderable(bool isLight) : light(isLight), colour(WHITE) {}
	virtual double intersect(Ray r) {
		return 0;
	};
	virtual Ray intersection(Vector collide, Ray r) {
		return r;
	};
};
