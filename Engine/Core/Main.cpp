
#include <iostream>
#include <cmath>
#include "../Math/Vector3.hpp"

bool nearlyEqual(float a, float b, float epsilon = 0.0001f)
{
    return std::abs(a - b) < epsilon;
}

bool checkVector(const Vector3& v, float x, float y, float z)
{
    return nearlyEqual(v.x, x)
        && nearlyEqual(v.y, y)
        && nearlyEqual(v.z, z);
}

void printResult(const char* testName, bool success)
{
    std::cout << (success ? "[PASS] " : "[FAIL] ")
              << testName << '\n';
}

int main()
{
    std::cout << "Vector3 Tests\n\n";

    std::cout << "Constructors\n";

    Vector3 zero;
    printResult("Default constructor",
        checkVector(zero, 0.0f, 0.0f, 0.0f));

    Vector3 a(1.0f, 2.0f, 3.0f);
    printResult("Parameterized constructor",
        checkVector(a, 1.0f, 2.0f, 3.0f));

    std::cout << "\nadditions/substractions\n";

    Vector3 b(4.0f, 5.0f, 6.0f);

    printResult("Addition",
        checkVector(a + b, 5.0f, 7.0f, 9.0f));

    printResult("Subtraction",
        checkVector(b - a, 3.0f, 3.0f, 3.0f));

    // 3. Multiplication et division
    std::cout << "\n scalar\n";

    printResult("Scalar *",
        checkVector(a * 2.0f, 2.0f, 4.0f, 6.0f));

    printResult("Scalar /",
        checkVector(b / 2.0f, 2.0f, 2.5f, 3.0f));

    // 4. Opérateurs composés
    std::cout << "\nthe weird things that are kinda cool\n";

    Vector3 c(1.0f, 2.0f, 3.0f);

    c += Vector3(1.0f, 1.0f, 1.0f);
    printResult("operator+=",
        checkVector(c, 2.0f, 3.0f, 4.0f));

    c -= Vector3(1.0f, 1.0f, 1.0f);
    printResult("operator-=",
        checkVector(c, 1.0f, 2.0f, 3.0f));

    c *= 2.0f;
    printResult("operator*=",
        checkVector(c, 2.0f, 4.0f, 6.0f));

    // 5. Produit scalaire et vectoriel
    std::cout << "\nscalar product and vectorial product (idk how its called in english)\n";

    Vector3 xAxis(1.0f, 0.0f, 0.0f);
    Vector3 yAxis(0.0f, 1.0f, 0.0f);
    Vector3 zAxis(0.0f, 0.0f, 1.0f);

    printResult("perpendicular vectors",
        nearlyEqual(xAxis.dot(yAxis), 0.0f));

    printResult("parallel vectors",
        nearlyEqual(xAxis.dot(xAxis), 1.0f));

    printResult("X x Y = Z",
        checkVector(xAxis.cross(yAxis), 0.0f, 0.0f, 1.0f));

    printResult("Y x X = -Z",
        checkVector(yAxis.cross(xAxis), 0.0f, 0.0f, -1.0f));

    std::cout << "\nlength and normalization\n";

    Vector3 d(3.0f, 4.0f, 0.0f);

    printResult("Length",
        nearlyEqual(d.length(), 5.0f));

    printResult("Normalized vector",
        checkVector(d.normalized(), 0.6f, 0.8f, 0.0f));

    printResult(" length 1",
        nearlyEqual(d.normalized().length(), 1.0f));

    std::cout << "\nextreme cases \n";

    Vector3 nullVector(0.0f, 0.0f, 0.0f);

    printResult("Zero vector length",
        nearlyEqual(nullVector.length(), 0.0f));

    printResult("Zero vector normalization",
        checkVector(nullVector.normalized(), 0.0f, 0.0f, 0.0f));

    printResult("parallel vectors vectorial product",
        checkVector(xAxis.cross(xAxis), 0.0f, 0.0f, 0.0f));

    std::cout << "\nyipeeeeeee\n";

    return 0;
}
