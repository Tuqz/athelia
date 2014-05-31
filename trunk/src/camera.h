#pragma once

#include "vector.h"
#include "ray.h"
#include <vector>

class Camera {
	public:
	Vector normal;
	Vector up;
	Vector position;
	Camera();
	Camera(Vector n, Vector u, Vector pos);
	int pixels = 250;
	std::vector<Ray> rays;
	void reset_rays();

	private:
	void gen_rays();
};
