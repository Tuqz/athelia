#pragma once
#include "vector.h"
#include "ray.h"
#include "renderable.h"

class Triangle : public Renderable {
	public:
	Vector a, b, c, normal;
	double d;
	Triangle(Vector A, Vector B, Vector C, Colour col, bool isLight);
	double intersect(Ray r);
	Ray intersection(Vector collide, Ray r);
};
