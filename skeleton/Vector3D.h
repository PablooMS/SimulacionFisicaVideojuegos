#pragma once
class Vector3D
{
public:
	Vector3D() : x(0), y(0), z(0) {}
	Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

	float magnitude();
	Vector3D normalized();

	Vector3D scalar(float n);

	float scalar(Vector3D other);

	Vector3D operator=(Vector3D other);
	Vector3D operator+(Vector3D other);
	Vector3D operator-(Vector3D other);
	Vector3D operator*(Vector3D other);

	float getX();
	float getY();
	float getZ();

private:
	float x;
	float y;
	float z;
};

