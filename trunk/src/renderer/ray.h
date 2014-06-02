#pragma once

#include "vector.h"
#include "colour.h"
#include <vector>

class Ray {
	public:
	Vector start;
	Vector direction;
	Colour colour;
	Ray();
	Ray(Vector s, Vector d);
	int bounces;
};
