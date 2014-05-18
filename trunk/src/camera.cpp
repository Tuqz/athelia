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
			double scale_x = ((2*i) - pixels)/pixels;
			double scale_y = ((2*j) - pixels)/pixels;
			Vector dir = normal + (lateral*scale_x) + (up*scale_y);
			rays[(i*pixels)+j] = Ray(position, dir/dir.magnitude());
		}
	}
}
