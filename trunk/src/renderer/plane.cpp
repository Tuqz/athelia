#include "plane.h"
#include <cmath>

Plane::Plane(Vector pos, Vector norm, Vector u, double w, double h, Colour col, bool isLight) : colour(col) {
	position = pos;
	normal = norm;
	d = Vector::dot(norm, pos);
	up = u;
	lateral = Vector::cross(normal, up);
	width = w;
	height = h;
	light = isLight;
}


double Plane::collide(Ray ray) {
	double dir_dot_norm = Vector::dot(ray.direction, normal);
	if(dir_dot_norm) {
		double time = ((double)d - Vector::dot(ray.start, normal))/dir_dot_norm;
		if(time >= 0) {
			Vector intersect = ray.start + ray.direction*time;
			Vector rel_pos = intersect - position;
			if(std::abs(Vector::dot(rel_pos, lateral)) <= width/2.0 && std::abs(Vector::dot(rel_pos, up)) <= height/2.0) {
				return time;
			}
		}
	}
	return -1;
}
