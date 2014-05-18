#pragma once

#include "vector.h"
#include "ray.h"

class Camera {
	public:
	Vector normal;
	Vector up;
	Vector position;
	Camera();
	Camera(Vector n, Vector u, Vector pos);
	Ray rays[];

	private:
	static int pixels;
	void gen_rays();
};
