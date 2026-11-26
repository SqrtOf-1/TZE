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
