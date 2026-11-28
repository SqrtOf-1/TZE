#include "Vector4.hpp"
#include <cmath>
#include <cassert>

Vector4::Vector4()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    w = 0.0f;
}

Vector4::Vector4(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Vector4 Vector4::operator+(const Vector4& other) const
{
        return Vector4(
        x + other.x,
        y + other.y,
        z + other.z,
        w + other.w
    );
// point + vector = point, vector + vector = vector, poit + vector = point, point - point = vector It all makes sense
//point + point = point : we have the average point since we need to diivide by w
}

Vector4 Vector4::operator-(const Vector4& other) const
{
        return Vector4(
        x - other.x,
        y - other.y,
        z - other.z,
        w - other.w
    );

}

Vector4 Vector4::operator*(float scalar) const
{
    return Vector4(
        x * scalar,
        y * scalar,
        z * scalar,
        w * scalar
    );
}

Vector4 Vector4::operator/(float scalar) const
{
    assert(scalar != 0.0f);
    return Vector4(
        x / scalar,
        y / scalar,
        z / scalar,
        w / scalar
    );
}

float Vector4::dot(const Vector4& other) const
{
    return (
        x * other.x +
        y * other.y +
        z * other.z +
        w * other.w);
}

float Vector4::length() const
{
    return std::sqrt(
        x * x +
        y * y +
        z * z +
        w * w
    );
}

Vector4 Vector4::normalized() const
{
    float len = length();

    if (len == 0.0f)
    {
        return Vector4(0.0f, 0.0f, 0.0f, 0.0f);
    }

    return Vector4(
        x / len,
        y / len,
        z / len,
        w / len
    );
}
