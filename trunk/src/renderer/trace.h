#pragma once
#include "ray.h"
#include "colour.h"
#include "renderable.h"
namespace Renderer {
	Colour trace(Ray ray, std::vector<Renderable*> entities);
}
