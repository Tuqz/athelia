#pragma once
#include "vector.h"
#include "ray.h"
#include <cmath>

class Light {
	public:
	Vector position;
	Vector normal;
	Vector up;
	Vector lateral;
	double d;
	double intensity;
	double width;
	double height;
	Light(Vector pos, Vector norm, Vector u, double w, double h, double intens);
	int collide(Ray ray);
};
