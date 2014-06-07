#include "trace.h"
#include <algorithm>
#include <iostream>

static int sign(double x)
{
	return 2 * (x >= 0) - (x == 0) - 1;
}

static bool aligned(Ray ray, Renderable object) {
	Vector rel_pos = object.position-ray.start;
	const double rays[3] = {ray.direction.x, ray.direction.y, ray.direction.z};
	const double rel_poses[3] = {rel_pos.x, rel_pos.y, rel_pos.z};
	bool alignment = true;
	for(int i = 0; i < 3; ++i) {
		int sign_plus = sign(rel_poses[i]+object.size);
		int sign_minus = sign(rel_poses[i]-object.size);
		alignment = alignment && ((sign(rays[i]) == sign_plus) || (sign(rays[i]) == sign_minus) || (!(sign_plus + sign_minus) && !sign(rays[i])));
	}
	return alignment;
}

Colour trace(Ray ray, std::vector<Renderable*> entities) {
	while(ray.bounces < MAX_RAY_BOUNCE) {
		std::vector<std::pair<double, Renderable*>> times;
		for(int i = 0; i < entities.size(); ++i) {
			if(aligned(ray, *entities[i])) {
				double time = (*entities[i]).intersect(ray);
				if(time > 0) {
					times.push_back(std::make_pair(time, entities[i]));
				}
			}
		}
		if(times.empty()) {
			return ray.colour*SKY;
		} else {
			auto min_pair = std::min_element(std::begin(times), std::end(times), [] (std::pair<double, Renderable*> i, std::pair<double, Renderable*> j) {return i.first < j.first;});
			std::pair<double, Renderable*> min_elem = *min_pair;
			double min_time = min_elem.first;
			Renderable* collider = min_elem.second;
			Vector pos = ray.start + ray.direction*min_time;
			ray = (*collider).intersection(pos, ray);
		}
	}
	return ray.colour;
}
