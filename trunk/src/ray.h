#pragma once

#include "vector.h"

class Ray {
	public:
	Vector start;
	Vector direction;
	double intensity;
	Ray();
	Ray(Vector s, Vector d);
};
