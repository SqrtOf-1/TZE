#include "Engine.hpp"
#include <iostream>
#include "../Math/Matrix4.hpp"
#include <numbers>

int main()
{
    Engine engine;

    engine.initialize();
    engine.run();
    engine.shutdown();

    Matrix4 rotation = Matrix4::rotationZ(std::numbers::pi_v<float> / 2.0f);
    rotation.print();

    return 0;
}