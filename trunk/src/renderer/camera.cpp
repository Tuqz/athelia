#include "camera.h"
#include <cmath>

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

void Camera::reset_rays() {
	rays.clear();
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

void Camera::pan(double angle) {
	normal = rotate(up, normal, angle);
	rays.clear();
	gen_rays();
}

void Camera::tilt(double angle) {
	Vector lateral = Vector::cross(normal, up);
	normal = rotate(lateral, normal, angle);
	up = Vector::cross(lateral, normal);
	rays.clear();
	gen_rays();
}

void Camera::roll(double angle) {
	up = rotate(normal, up, angle);
	rays.clear();
	gen_rays();
}

void Camera::translate(Vector trans) {
	position = position + trans;
	rays.clear();
	gen_rays();
}

Vector Camera::rotate(Vector rot, Vector vec, double angle) {
	double cangle = cos(angle);
	double sangle = sin(angle);
	double factor = 1-cangle;
	Vector v = vec;
	vec.x = (cangle + rot.x*rot.x*factor)*v.x + (rot.x*rot.y*factor - rot.z*sangle)*v.y + (rot.x*rot.z*factor + rot.y*sangle)*v.z;
	vec.y = (rot.x*rot.y*factor+rot.z*sangle)*v.x + (cangle+rot.y*rot.y*factor)*v.y + (rot.y*rot.z*factor-rot.x*sangle)*v.z;
	vec.z = (rot.x*rot.z*factor-rot.y*sangle)*v.x + (rot.y*rot.z*factor+rot.x*sangle)*v.y + (cangle+rot.z*rot.z*factor)*v.z;
	return vec;
}
