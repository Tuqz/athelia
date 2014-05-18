#include "ray.h"

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
