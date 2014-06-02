#include "ray.h"

Ray::Ray() : colour(WHITE) {
	start = {0, 0, 0};
	direction = {0, 0, 0};
	bounces = 0;
}

Ray::Ray(Vector s, Vector d) : colour(WHITE) {
	start = s;
	direction = d;
	bounces = 0;
}
