#include "cube.h"
#include "colour.h"

Cube::Cube(Vector pos) {
	position = pos;
	size = 1;
	gen_faces(WHITE);
}

Cube::Cube(Vector pos, double dim) {
	position = pos;
	size = dim;
	gen_faces(WHITE);
}

Cube::Cube(Vector pos, Colour colour) {
	position = pos;
	size = 1;
	gen_faces(colour);
}

Cube::Cube(Vector pos, double dim, Colour colour) {
	position = pos;
	size = dim;
	gen_faces(colour);
}

void Cube::gen_faces(Colour colour) {
	std::array<Vector, 6> normals;
	normals[0] = Vector(0, 1, 0);
	normals[1] = Vector(1, 0, 0);
	normals[2] = Vector(0, 0, 1);
	normals[3] = Vector(-1, 0, 0);
	normals[4] = Vector(0, 0, -1);
	normals[5] = Vector(0, -1, 0);
	faces[0] = Plane(position+normals[0]*size/2, normals[0], normals[1], size, size, colour, false);
	faces[1] = Plane(position+normals[1]*size/2, normals[1], normals[2], size, size, colour, false);
	faces[2] = Plane(position+normals[2]*size/2, normals[2], normals[3], size, size, colour, false);
	faces[3] = Plane(position+normals[3]*size/2, normals[3], normals[4], size, size, colour, false);
	faces[4] = Plane(position+normals[4]*size/2, normals[4], normals[5], size, size, colour, false);
	faces[5] = Plane(position+normals[5]*size/2, normals[5], normals[1], size, size, colour, false);
}
