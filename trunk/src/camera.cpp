#include "camera.h"

Camera::Camera() {
	normal = {1, 0, 0};
	up = {0, 1, 0};
	position = {0, 0, 0};
	gen_rays();
}

Camera::Camera(Vector n, Vector u, Vector pos) {
	normal = n;
	up = u;
	position = pos;
	gen_rays();
}

void Camera::gen_rays() {
	for(int i = 0; i < pixels; ++i) {
		for(int j = 0; j < pixels; ++j) {
			Vector lateral = Vector::cross(normal, up);
			double x = (2.0*i)/(pixels-1) - 1;
			double y = (2.0*j)/(pixels-1) - 1;
			Vector dir = lateral*x + up*y + normal;
			rays.push_back(Ray(position, dir/dir.magnitude()));
		}
	}
}
