#pragma once

class Colour {
	public:
	double red;
	double green;
	double blue;
	Colour(double r, double g, double b);
	Colour operator * (const Colour& other);
};

#define RED Colour(1, 0, 0)
#define GREEN Colour(0, 1, 0)
#define BLUE Colour(0, 0, 1)
#define YELLOW Colour(1, 1, 0)
#define CYAN Colour(0, 1, 1)
#define MAGENTA Colour(1, 0, 1)
#define WHITE Colour(1, 1, 1)
#define BLACK Colour(0, 0, 0)
