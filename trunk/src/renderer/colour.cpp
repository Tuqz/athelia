#include "colour.h"
namespace Renderer {
	Colour::Colour(double r, double g, double b) {
		red = r;
		green = g;
		blue = b;
	}

	Colour Colour::operator * (const Colour& other) {
		return Colour(red*other.red, green*other.green, blue*other.blue);
	}

	Colour Colour::operator * (const double& scale) {
		return Colour(red*scale, green*scale, blue*scale);
	}
}
