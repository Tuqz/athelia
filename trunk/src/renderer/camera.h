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
	void pan(double angle);
	void tilt(double angle);
	void roll(double angle);
	void translate(Vector trans);

	private:
	void gen_rays();
	Vector rotate(Vector rot, Vector vec, double angle);
};
