#pragma once
#include "ray.h"
#include "plane.h"
#include "cube.h"
#include "colour.h"

Colour trace(Ray ray, std::vector<Plane> entities);
Colour trace(Ray ray, std::vector<Plane> entities, std::vector<Cube> cubes);
