#include "trace.h"
#include <algorithm>

static int sign(double x)
{
	return 2 * (x >= 0) - (x == 0) - 1;
}

static bool alignment(Ray ray, Cube cube, int dir) {
	Vector rel_pos = cube.position-ray.start;
	const double rays[3] = {ray.direction.x, ray.direction.y, ray.direction.z};
	const double rel_poss[3] = {rel_pos.x, rel_pos.y, rel_pos.z};
	return sign(rel_poss[dir]+cube.size/2) == sign(rays[dir]) || sign(rel_poss[dir]-cube.size/2) == sign(rays[dir]);
}

Colour trace(Ray ray, std::vector<Plane> entities) {
	while(ray.bounces < 10) {
		std::vector<std::pair<double, Plane>> times;
		for(int i = 0; i < entities.size(); ++i) {
			double time = entities[i].collide(ray);
			if(time > 0) {
				times.push_back(std::make_pair(time, entities[i]));
			}
		}
		if(times.empty()) {
			return ray.colour*SKY;
		} else {
			auto min_pair = std::min_element(std::begin(times), std::end(times), [] (std::pair<double, Plane> i, std::pair<double, Plane> j) {return i.first < j.first;});
			std::pair<double, Plane> min_elem = *min_pair;
			double min_time = min_elem.first;
			Plane collider = min_elem.second;
			ray.colour = ray.colour*collider.colour;
			if(!collider.light) {
				ray.start = ray.start + ray.direction * min_time;
				ray.direction = ray.direction - collider.normal*2*Vector::dot(collider.normal, ray.direction);
				ray.bounces += 1;
			} else {
				return ray.colour;
			}
		}
	}
}

Colour trace(Ray ray, std::vector<Plane> entities, std::vector<Cube> cubes) {
	while(ray.bounces < 10) {
		std::vector<Plane> collid_ents = entities;
		for(int i = 0; i < cubes.size(); ++i) {
			if(alignment(ray, cubes[i], 1) && alignment(ray, cubes[i], 2) && alignment(ray, cubes[i], 3)) {
				for(int j = 0; j < 6; ++j) {
					if(Vector::dot(cubes[i].faces[j].normal, ray.direction) < 0) {
						collid_ents.push_back(cubes[i].faces[j]);
					}
				}
			}
		}
		std::vector<std::pair<double, Plane>> times;
		for(int i = 0; i < collid_ents.size(); ++i) {
			double time = collid_ents[i].collide(ray);
			if(time > 0) {
				times.push_back(std::make_pair(time, collid_ents[i]));
			}
		}
		if(times.empty()) {
			return ray.colour*SKY;
		} else {
			auto min_pair = std::min_element(std::begin(times), std::end(times), [] (std::pair<double, Plane> i, std::pair<double, Plane> j) {return i.first < j.first;});
			std::pair<double, Plane> min_elem = *min_pair;
			double min_time = min_elem.first;
			Plane collider = min_elem.second;
			ray.colour = ray.colour*collider.colour;
			if(!collider.light) {
				ray.start = ray.start + ray.direction * min_time;
				ray.direction = ray.direction - collider.normal*2*Vector::dot(collider.normal, ray.direction);
				ray.bounces += 1;
			} else {
				return ray.colour;
			}
		}
	}
}
