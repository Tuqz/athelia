#include "colour.h"

Colour::Colour(double r, double g, double b) {
	red = r;
	green = g;
	blue = b;
}

Colour Colour::operator * (const Colour& other) {
	return Colour(red*other.red, green*other.green, blue*other.blue);
}
