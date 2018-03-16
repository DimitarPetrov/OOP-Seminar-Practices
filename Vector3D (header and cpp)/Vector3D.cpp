#include "Vector3D.h"
#include <iostream>
#include <cmath>

Vector3D::Vector3D() {
	x = y = z = 0;
}

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

Vector3D::Vector3D(Point3D const& start, Point3D const& end) {
	x = end.x - start.x;
	y = end.y - start.y;
	z = end.z - start.z;
}

double Vector3D::getX() const{
	return x;
}

double Vector3D::getY() const{
	return y;
}

double Vector3D::getZ() const{
	return z;
}

void Vector3D::setX(double x) {
	this->x = x;
}

void Vector3D::setY(double y) {
	this->y = y;
}

void Vector3D::setZ(double z) {
	this->z = z;
}

void Vector3D::print() const{
	std::cout << "(" << getX() << "," << getY() << "," << getZ() << ")" << std::endl;
}

double Vector3D::length() const{
	return sqrt(getX() * getX() + getY()*getY() + getZ()*getZ());
}

void Vector3D::scale(double scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

void Vector3D::normalize() {
	x /= length();
	y /= length();
	z /= length();
}

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
