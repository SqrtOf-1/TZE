#include "Transform.hpp"

//Je vais utiliser l'ordre R = Rz * Ry * Rx

Transform::Transform()
{
    position.x = 0.0f; position.y = 0.0f; position.z = 0.0f;
    rotation.x = 0.0f; rotation.y = 0.0f; rotation.z = 0.0f;
    scale.x = 1.0f; scale.y = 1.0f; scale.z = 1.0f;
}

Matrix4 Transform::getModelMatrix() const
{
    Matrix4 T = Matrix4::translation(position);

    Matrix4 Rz = Matrix4::rotationZ(rotation.z);
    Matrix4 Ry = Matrix4::rotationY(rotation.y);
    Matrix4 Rx = Matrix4::rotationX(rotation.x);

    Matrix4 S = Matrix4::scale(scale);

    return T * Rz * Ry * Rx * S;

}