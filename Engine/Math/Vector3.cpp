#include "Vector3.hpp"
#include <cmath>

Vector3::Vector3()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3 Vector3::operator+(const Vector3& other) const
{
    return Vector3(
        x + other.x,
        y + other.y,
        z + other.z
    );
}

Vector3 Vector3::operator*(float scalar) const
{
    return Vector3(
        x * scalar,
        y * scalar,
        z * scalar
    );
}

float Vector3::length() const
{
    return std::sqrt(
        x * x +
        y * y +
        z * z
    );
}

Vector3 Vector3::normalized() const
{
    float len = length();

    if (len == 0.0f)
    {
        return Vector3(0.0f, 0.0f, 0.0f);
    }

    return Vector3(
        x / len,
        y / len,
        z / len
    );
}