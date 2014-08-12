#include "plane.h"
#include "colour.h"
#include <cmath>
#include <iostream>
namespace Renderer {
	Plane::Plane() : Renderable(false, WHITE) {
		position = Vector(0, 0, 0);
		normal = Vector(0, 1, 0);
		d = Vector::dot(normal, position);
		up = Vector(1, 0, 0);
		lateral = Vector::cross(normal, up);
		width = 1;
		height = 1;
	}

	Plane::Plane(Vector pos, Vector norm, Vector u, double w, double h, Colour col, bool isLight) : Renderable(isLight, col) {
		position = pos;
		normal = norm;
		d = Vector::dot(norm, pos);
		up = u;
		lateral = Vector::cross(normal, up);
		width = w;
		height = h;
		size = std::max(width, height);
	}


	double Plane::intersect(Ray ray) {
		double dir_dot_norm = Vector::dot(ray.direction, normal);
		if(dir_dot_norm) {
			double time = (d - Vector::dot(ray.start, normal))/dir_dot_norm;
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

	Ray Plane::intersection(Vector collide, Ray ray) {
		Ray out;
		if(light) {
			out.bounces = MAX_RAY_BOUNCE;
			out.colour = ray.colour * colour;
		} else {
			Vector dir = ray.direction - normal * 2 * Vector::dot(ray.direction, normal);
			out = Ray(collide, dir);
			out.bounces = ray.bounces + 1;
			out.colour = ray.colour * colour * Vector::dot(normal, ray.direction);
		}
		return out;
	}
}
