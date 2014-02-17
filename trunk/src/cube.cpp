#include "cube.h"

Cube::Cube() {
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	size = 0;
	gen_arrays();
}

Cube::Cube(double cntrx, double cntry, double cntrz, double scale) {
	pos.x = cntrx;
	pos.y = cntry;
	pos.z = cntrz;
	size = scale;
	gen_arrays();
}

Cube::Cube(Vector place, double scale) {
	pos = place;
	size = scale;
	gen_arrays();
}

const int Cube::faces[6][4] = {{0, 1, 2, 4}, {0, 1, 3, 5}, {1, 5, 4, 7}, {0, 3, 2, 6}, {3, 5, 6, 7}, {2, 4, 6, 7}};

void Cube::gen_arrays() {
	verts[0] = {pos.x + (size / 2), pos.y + (size / 2), pos.z + (size / 2)};
	verts[1] = {pos.x - (size / 2), pos.y + (size / 2), pos.z + (size / 2)};
	verts[2] = {pos.x + (size / 2), pos.y - (size / 2), pos.z + (size / 2)};
	verts[3] = {pos.x + (size / 2), pos.y + (size / 2), pos.z - (size / 2)};
	verts[4] = {pos.x - (size / 2), pos.y - (size / 2), pos.z + (size / 2)};
	verts[5] = {pos.x - (size / 2), pos.y + (size / 2), pos.z - (size / 2)};
	verts[6] = {pos.x + (size / 2), pos.y - (size / 2), pos.z - (size / 2)};
	verts[7] = {pos.x - (size / 2), pos.y - (size / 2), pos.z - (size / 2)};
}
