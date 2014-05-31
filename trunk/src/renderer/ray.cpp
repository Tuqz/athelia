#include "ray.h"
#include <algorithm>

Ray::Ray() {
	start = {0, 0, 0};
	direction = {0, 0, 0};
	intensity = 1;
}

Ray::Ray(Vector s, Vector d) {
	start = s;
	direction = d;
	intensity = 1;
}

void Ray::trace(std::vector<Plane> entities) {
	while(1) {
		std::vector<double> times;
		std::vector<std::pair<int, int>> key;
		for(int i = 0; i < entities.size(); ++i) {
			double time = entities[i].collide(*this);
			if(time > 0) {
				times.push_back(time);
				key.push_back(std::make_pair(times.size()-1, i));
			}
		}
		if(times.empty()) {
			intensity = 0;
			return;
		} else {
			std::vector<double>::iterator min_elem = std::min_element(std::begin(times), std::end(times));
			double min_time = *min_elem;
			int pos = std::distance(times.begin(), min_elem);
			int plane_no = 0;
			for(int i = 0; i < key.size(); ++i) {
				if(key[i].first == pos) {
					plane_no = key[i].second;
				}
			}
			Plane collider = entities[plane_no];
			intensity *= collider.intensity;
			if(!collider.light) {
				start = start + direction * min_time;
				direction = direction - collider.normal*2*Vector::dot(collider.normal, direction);
			} else {
				return;
			}
		}
	}
}
