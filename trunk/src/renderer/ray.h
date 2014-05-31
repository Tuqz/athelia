#pragma once

#include "vector.h"
#include "plane.h"
#include <vector>

class Plane;
class Ray {
	public:
	Vector start;
	Vector direction;
	double intensity;
	Ray();
	Ray(Vector s, Vector d);
	void trace(std::vector<Plane> entities);
};

