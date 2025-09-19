#include "Vector3D.h"
#include <math.h>

float Vector3D::magnitude()
{
    return sqrt(x * x + y * y + z * z);
}

Vector3D Vector3D::normalized()
{
    float mag = magnitude();
    return Vector3D(x / mag, y / mag, z / mag);
}

Vector3D Vector3D::scalar(float n)
{
    return Vector3D(x * n, y * n, z * n);
}

float Vector3D::scalar(Vector3D other)
{
    return x * other.x + y * other.y + z * other.z;
}

Vector3D Vector3D::operator=(Vector3D other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

Vector3D Vector3D::operator+(Vector3D other)
{
    return Vector3D(x + other.x, y + other.y, z + other.z);
}

Vector3D Vector3D::operator-(Vector3D other)
{
    return Vector3D(x - other.x, y - other.y, z - other.z);
}

Vector3D Vector3D::operator*(Vector3D other)
{
    return Vector3D(y * other.z - z * other.x, z * other.x - x * other.z, x * other.y - y * other.x);
}

float Vector3D::getX()
{
    return x;
}

float Vector3D::getY()
{
    return y;
}

float Vector3D::getZ()
{
    return z;
}
