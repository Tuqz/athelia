#include "cube.h"
#include "colour.h"
#include <algorithm>
#include <iostream>

Cube::Cube(Vector pos, bool isLight) : Renderable(isLight), position(pos) {
	colour = WHITE;
	size = 1;
	gen_faces();
}

Cube::Cube(Vector pos, double dim, bool isLight) : Renderable(isLight), position(pos) {
	colour = WHITE;
	size = dim;
	gen_faces();
}

Cube::Cube(Vector pos, Colour col, bool isLight) : Renderable(isLight), position(pos) {
	colour = col;
	size = 1;
	gen_faces();
}

Cube::Cube(Vector pos, double dim, Colour col, bool isLight) : Renderable(isLight), position(pos) {
	colour = col;
	size = dim;
	gen_faces();
}

double Cube::intersect(Ray r) {
	std::vector<double> times;
	for(int i = 0; i < 6; ++i) {
		if(Vector::dot(faces[i].normal, r.direction) < 0) {
			double time = faces[i].intersect(r);
			if(time > 0) {
				times.push_back(time);
			}
		}
	}
	if(times.empty()) {
		return -1;
	} else {
		double time = *std::min_element(times.begin(), times.end());
		return time;
	}
}

Ray Cube::intersection(Vector collide, Ray ray) {
	Ray out;
	if(!light) {
		Plane collider;
		for(int i = 0; i < 6; ++i) {
			if(Vector::dot(collide, faces[i].normal) == faces[i].d) {
				collider = faces[i];
				break;
			}
		}
		Vector dir = ray.direction - collider.normal*2*Vector::dot(collider.normal, ray.direction);
		out = Ray(collide, dir);
		out.bounces = ray.bounces + 1;
	} else {
		out.bounces = MAX_RAY_BOUNCE;
	}
	out.colour = ray.colour * colour;
	return out;
}

void Cube::gen_faces() {
	std::array<Vector, 6> normals;
	normals[0] = Vector(0, 1, 0);
	normals[1] = Vector(1, 0, 0);
	normals[2] = Vector(0, 0, 1);
	normals[3] = Vector(-1, 0, 0);
	normals[4] = Vector(0, 0, -1);
	normals[5] = Vector(0, -1, 0);
	faces[0] = Plane(position+normals[0]*size/2, normals[0], normals[1], size, size, colour, light);
	faces[1] = Plane(position+normals[1]*size/2, normals[1], normals[2], size, size, colour, light);
	faces[2] = Plane(position+normals[2]*size/2, normals[2], normals[3], size, size, colour, light);
	faces[3] = Plane(position+normals[3]*size/2, normals[3], normals[4], size, size, colour, light);
	faces[4] = Plane(position+normals[4]*size/2, normals[4], normals[5], size, size, colour, light);
	faces[5] = Plane(position+normals[5]*size/2, normals[5], normals[1], size, size, colour, light);
}