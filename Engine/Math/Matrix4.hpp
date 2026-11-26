#pragma once
#include "Vector3.hpp"

class Matrix4 {
public:
    float elements[16];

    Matrix4();

    static Matrix4 identity();

    Matrix4 operator*(const Matrix4& other) const;

    void print() const;

    static Matrix4 translation(const Vector3& position);

    static Matrix4 rotationZ(float angle);
};
