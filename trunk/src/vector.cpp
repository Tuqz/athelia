#include "vector.h"
#include <math.h>

Vector::Vector() {
	x = 0;
	y = 0;
	z = 0;
}

Vector::Vector(double in_x, double in_y, double in_z) {
	x = in_x;
	y = in_y;
	z = in_z;
}

Vector Vector::operator + (const Vector& other) {
	return {x + other.x, y + other.y, z + other.z};
}

Vector Vector::operator - (const Vector& other) {
	return {x - other.x, y - other.y, z - other.z};
}

Vector Vector::operator * (const double& other) {
	return {x * other, y * other, z * other};
}

Vector Vector::operator / (const double& other) {
	return {x / other, y / other, z / other};
}

double Vector::magnitude() {
	return sqrt(x*x + y*y + z*z);
}
