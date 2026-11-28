#include <iostream>
#include "../Math/Vector4.hpp"

void printVector(const Vector4& v)
{
    std::cout << "("
              << v.x << ", "
              << v.y << ", "
              << v.z << ", "
              << v.w << ")\n";
}

int main()
{
    std::cout << "Vector4 tests\n\n";

    Vector4 zero;
    Vector4 a(1.0f, 2.0f, 3.0f, 1.0f);
    Vector4 b(4.0f, 5.0f, 6.0f, 1.0f);

    std::cout << "default constructor\n";
    printVector(zero);

    std::cout << "parameterized constructor\n";
    printVector(a);

    std::cout << "Addition:\n";
    printVector(a + b);

    std::cout << "subtraction:\n";
    printVector(b - a);

    std::cout << "scalar multiplication:\n";
    printVector(a * 2.0f);

    std::cout << "scalar division:\n";
    printVector(b / 2.0f);

    std::cout << "dot product:\n";
    std::cout << a.dot(b) << "\n";

    std::cout << "length:\n";
    Vector4 c(1.0f, 2.0f, 2.0f, 0.0f);
    std::cout << c.length() << "\n";

    std::cout << "normalization:\n";
    Vector4 d(0.0f, 3.0f, 0.0f, 0.0f);
    printVector(d.normalized());

    std::cout << "zero vector normalization:\n";
    printVector(zero.normalized());

    std::cout << "point + Direction:\n";
    Vector4 point(1.0f, 2.0f, 3.0f, 1.0f);
    Vector4 direction(2.0f, 0.0f, 1.0f, 0.0f);
    printVector(point + direction);

    std::cout << "point - point:\n";
    Vector4 point2(4.0f, 5.0f, 6.0f, 1.0f);
    printVector(point2 - point);

    return 0;
}
