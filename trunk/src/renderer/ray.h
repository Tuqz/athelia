#pragma once

#include "vector.h"
#include "plane.h"
#include "colour.h"
#include <vector>

class Plane;
class Ray {
	public:
	Vector start;
	Vector direction;
	Colour colour;
	Ray();
	Ray(Vector s, Vector d);
	void trace(std::vector<Plane> entities);
};

