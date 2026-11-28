#pragma once

class Vector4 {
public:
    float x;
    float y;
    float z;
    float w;
//point : w != 1
//vecteur direction : w = 0
//de cette maniere, translater un vecteur ne change rien a la valeur du vecteur
//le quadruplet (x,y,z,w) représente le point (x/w, y/w, z/w)
//permet notamment de gérer la perspective (on s'eloigne un peu des maths là)

    Vector4();
    Vector4(float x, float y, float z, float w);

    Vector4 operator+(const Vector4& other) const;
    Vector4 operator*(float scalar) const;
    Vector4 operator-(const Vector4& other) const;
    Vector4 operator/(float scalar) const;
    float dot(const Vector4& other) const;

    float length() const;
    Vector4 normalized() const;


};
