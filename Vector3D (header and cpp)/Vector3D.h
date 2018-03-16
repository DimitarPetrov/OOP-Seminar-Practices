#ifndef VECTOR3D_H_VECTOR3D
#define VECTOR3D_H_VECTOR3D

struct Point3D {
	double x;
	double y;
	double z;

	Point3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
};

class Vector3D {

private:
	double x;
	double y;
	double z;
public:

	Vector3D();

	Vector3D(double x, double y, double z);

	Vector3D(Point3D const& start, Point3D const& end);

	double getX() const;

	double getY() const;

	double getZ() const;

	void setX(double x_);

	void setY(double y_);

	void setZ(double z_);

	void print() const;

	double length() const;

	void scale(double scalar);

	void normalize();
};

Vector3D sum(Vector3D a, Vector3D b);

double scalarProduct(Vector3D a, Vector3D b);

Vector3D vectorProduct(Vector3D a, Vector3D b);

double mixedProduct(Vector3D a, Vector3D b, Vector3D c);



#endif
