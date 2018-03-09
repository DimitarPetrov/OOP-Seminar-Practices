// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

struct Point3D {
	double x;
	double y;
	double z;
	
	Point3D(double x_ = 0, double y_ = 0, double z_ = 0) {
		x = x_;
		y = y_;
		z = z_;
	}
};

class Vector3D {

private:
	double x;
	double y;
	double z;
public:
	
	Vector3D() {
		x = y = z = 0;
	}

	Vector3D(double x_, double y_, double z_) {
		x = x_;
		y = y_;
		z = z_;
	}

	Vector3D(Point3D const& start, Point3D const& end) {
		x = end.x - start.x;
		y = end.y - start.y;
		z = end.z - start.z;
	}

	double getX() {
		return x;
	}

	double getY() {
		return y;
	}

	double getZ() {
		return z;
	}

	void setX(double x_) {
		x = x_;
	}

	void setY(double y_) {
		y = y_;
	}

	void setZ(double z_) {
		z = z_;
	}

	void print() {
		cout << "(" << getX() << "," << getY() << "," << getZ() << ")" << endl;
	}

	double length() {
		return sqrt(getX() * getX() + getY()*getY() + getZ()*getZ());
	}

	void scale(double scalar) {
		x *= scalar;
		y *= scalar;
		z *= scalar;
	}

	void normalize() {
		x /= length();
		y /= length();
		z /= length();
	}
};

Vector3D sum(Vector3D a, Vector3D b) {
	return Vector3D(a.getX() + b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ());
}

double scalarProduct(Vector3D a, Vector3D b) {
	return a.getX() * b.getX() + a.getY() * b.getY() + a.getZ() * b.getZ();
}

Vector3D vectorProduct(Vector3D a, Vector3D b) {
	return Vector3D(a.getY()*b.getZ() - a.getZ()*b.getY(), a.getZ()*b.getX() - a.getX()*b.getZ(),
		a.getX()*b.getY() - a.getY()*b.getX());
}

double mixedProduct(Vector3D a, Vector3D b, Vector3D c) {
	return scalarProduct(vectorProduct(a, b), c);
}



int main()
{
	Vector3D a(1, 2, 3);
	Vector3D b(4, 5, 6);
	cout << scalarProduct(vectorProduct(a, b), a) << endl;
}

