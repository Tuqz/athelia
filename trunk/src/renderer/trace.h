#pragma once
#include "ray.h"
#include "colour.h"
#include "renderable.h"

Colour trace(Ray ray, std::vector<Renderable*> entities);
