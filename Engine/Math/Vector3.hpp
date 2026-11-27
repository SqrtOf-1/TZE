#pragma once

class Vector3 {
public:
    float x;
    float y;
    float z;

    Vector3();

    Vector3(float x, float y, float z);

    Vector3 operator+(const Vector3& other) const;

    Vector3 operator*(float scalar) const;

    float length() const;

    Vector3 normalized() const;

    Vector3 operator-(const Vector3& other) const;

    float dot(const Vector3& other) const;
    Vector3 cross(const Vector3& other) const;

    Vector3& operator+=(const Vector3& other);
    Vector3& operator-=(const Vector3& other);
    Vector3& operator*=(float scalar);

    Vector3 operator/(float scalar) const;
};