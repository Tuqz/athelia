#include "triangle.h"
#include <algorithm>

Triangle::Triangle(Vector A, Vector B, Vector C, Colour col, bool isLight) : Renderable(isLight, col) {
	a = A;
	b = B;
	c = C;
	Vector ab = a-b;
	Vector ac = a-c;
	Vector norm = Vector::cross(ab, ac);
	normal = norm/norm.magnitude();
	d = Vector::dot(normal, a);
	double xposes[3] = {a.x, b.x, c.x};
	double yposes[3] = {a.y, b.y, c.y};
	double zposes[3] = {a.z, b.z, c.z};
	double extremes[6];
	extremes[0] = *std::min_element(xposes, xposes+3);
	extremes[1] = *std::max_element(xposes, xposes+3);
	extremes[2] = *std::min_element(yposes, yposes+3);
	extremes[3] = *std::max_element(yposes, yposes+3);
	extremes[4] = *std::min_element(zposes, zposes+3);
	extremes[5] = *std::max_element(zposes, zposes+3);
	double sizes[3];
	for(int i = 0; i < 3; ++i) {
		sizes[i] = extremes[2*i+1]-extremes[2*i];
	}
	size = *std::max_element(sizes, sizes+3);
}

double Triangle::intersect(Ray r) {
	double dir_dot_norm = Vector::dot(r.direction, normal);
	if(dir_dot_norm) {
		double time = (d - Vector::dot(r.start, normal))/dir_dot_norm;
		if(time >= 0) {
			Vector intersect = r.start + r.direction*time;
			Vector points[3] = {a, b, c};
			Vector dirs[3];
			for(int i = 0; i < 3; ++i) {
				dirs[i] = points[i] - intersect;
				dirs[i] = dirs[i]/dirs[i].magnitude();
			}
			double dots[3];
			for(int i = 0; i < 3; ++i) {
				if(i == 2) {
					dots[2] = Vector::dot(dirs[2], dirs[0]);
				} else {
					dots[i] = Vector::dot(dirs[i], dirs[i+1]);
				}
			}
			double total = 0;
			for(int i = 0; i < 3; ++i) {
				total += acos(dots[i]);
			}
			double pi = 3.14159;
			if(total >= 2*pi) {
				return time;
			}
		}
	}
	return -1;
}

Ray Triangle::intersection(Vector collide, Ray r) {
	Ray out;
	if(light) {
		out.bounces = MAX_RAY_BOUNCE;
		out.colour = r.colour * colour;
	} else {
		Vector dir = r.direction - normal * 2 * Vector::dot(r.direction, normal);
		out = Ray(collide, dir);
		out.bounces = r.bounces + 1;
	}
	return out;
}
