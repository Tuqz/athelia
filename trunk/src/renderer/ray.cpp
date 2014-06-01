#include "ray.h"
#include <algorithm>

Ray::Ray() : colour(WHITE) {
	start = {0, 0, 0};
	direction = {0, 0, 0};
}

Ray::Ray(Vector s, Vector d) : colour(WHITE) {
	start = s;
	direction = d;
}

void Ray::trace(std::vector<Plane> entities) {
	while(1) {
		std::vector<std::pair<double, Plane>> times;
		for(int i = 0; i < entities.size(); ++i) {
			double time = entities[i].collide(*this);
			if(time > 0) {
				times.push_back(std::make_pair(time, entities[i]));
			}
		}
		if(times.empty()) {
			colour = BLACK;
			return;
		} else {
			auto min_pair = std::min_element(std::begin(times), std::end(times), [] (std::pair<double, Plane> i, std::pair<double, Plane> j) {return i.first < j.first;});
			std::pair<double, Plane> min_elem = *min_pair;
			double min_time = min_elem.first;
			Plane collider = min_elem.second;
			colour = colour*collider.colour;
			if(!collider.light) {
				start = start + direction * min_time;
				direction = direction - collider.normal*2*Vector::dot(collider.normal, direction);
			} else {
				return;
			}
		}
	}
}
