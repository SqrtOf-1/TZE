#include "Matrix4.hpp"
#include <iostream>
#include <cmath>

Matrix4::Matrix4()
{
    for (int i = 0; i < 16; i++)
    {
        elements[i] = 0.0f;
    }
}


Matrix4 Matrix4::identity()
{
    Matrix4 result;

    result.elements[0]  = 1.0f;
    result.elements[5]  = 1.0f;
    result.elements[10] = 1.0f;
    result.elements[15] = 1.0f;
//fun fact : j'avais fait deux boucles imbriquées pour configurer toutes les valeurs de la matrice identité alors que mon constructeur Matrix4 mettait déjà tout à 0
//maintenant c'est plus simple mdrrrr, ça c'est de l'optimisation

    return result;
}


Matrix4 Matrix4::operator*(const Matrix4& other) const
{
    Matrix4 result;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                result.elements[4 * i + j] +=
                    elements[4 * i + k] *
                    other.elements[4 * k + j];
            }
        }
    }

    return result;
}

void Matrix4::print() const
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << elements[4 * i + j] << "\t";
        }

        std::cout << std::endl;
    }
}

Matrix4 Matrix4::translation(const Vector3& position)
{
    Matrix4 result = Matrix4::identity();

    result.elements[3] = position.x;
    result.elements[7] = position.y;
    result.elements[11] = position.z;
//Ce sont ces positions là car je considere le tableau (a00 a01 a02 ... a1515) comme la matrice
//a00 a01 ...
//a10 a11
//les lignes puis les colonnes, du coup on doit faire elements[4*ligne + colonne]

    return result;
}


Matrix4 Matrix4::rotationZ(float angle)
{
    Matrix4 result = Matrix4::identity();

    result.elements[0] = std::cos(angle);
    result.elements[1] = -std::sin(angle);
    result.elements[4] = std::sin(angle);
    result.elements[5] = std::cos(angle);

    return result;
}

Matrix4 Matrix4::rotationX(float angle)
{
    Matrix4 result = Matrix4::identity();

    result.elements[5] = std::cos(angle);
    result.elements[6] = -std::sin(angle);
    result.elements[9] = std::sin(angle);
    result.elements[10] = std::cos(angle);

    return result;
}

Matrix4 Matrix4::rotationY(float angle)
{
    Matrix4 result = Matrix4::identity();

    result.elements[0] = std::cos(angle);
    result.elements[2] = std::sin(angle);
    result.elements[8] = -std::sin(angle);
    result.elements[10] = std::cos(angle);

    return result;
}

Matrix4 Matrix4::scale(const Vector3& factors)
{
    Matrix4 result = Matrix4::identity();

    result.elements[0] = factors.x;
    result.elements[5] = factors.y;
    result.elements[10] = factors.z;

    return result;
}

Vector4 Matrix4::operator*(const Vector4& vector) const
{
    Vector4 result;
    result.x = elements[0] * vector.x + elements[1] * vector.y + elements[2] * vector.z + elements[3] * vector.w;
    result.y = elements[4] * vector.x + elements[5] * vector.y + elements[6] * vector.z + elements[7] * vector.w;
    result.z = elements[8] * vector.x + elements[9] * vector.y + elements[10] * vector.z + elements[11] * vector.w;
    result.w = elements[12] * vector.x + elements[13] * vector.y + elements[14] * vector.z + elements[15] * vector.w;
//Pas très élégant mais les autres solution était plus longues et utilisait des tableaux temporaires et des boucles imbriquées
    return result;
}