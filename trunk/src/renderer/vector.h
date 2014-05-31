#pragma once

class Vector {
	public:
	double x, y, z;
	Vector();
	Vector(double in_x, double in_y, double in_z);

	double magnitude();

	Vector operator + (const Vector& other);
	Vector operator - (const Vector& other);
	Vector operator * (const double& other);
	Vector operator / (const double& other);
	static double dot(Vector a, Vector b);
	static Vector cross(Vector a, Vector b);
};
