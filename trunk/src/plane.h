#pragma once
#include "vector.h"
#include "ray.h"
#include <cmath>

class Ray;
class Plane {
	public:
	Vector position;
	Vector normal;
	Vector up;
	Vector lateral;
	double d;
	double intensity;
	double width;
	double height;
	Plane(Vector pos, Vector norm, Vector u, double w, double h, double intens, bool isLight);
	double collide(Ray ray);
	bool light;
};
