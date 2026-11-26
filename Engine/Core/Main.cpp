#include "Engine.hpp"
#include <iostream>
#include "../Math/Matrix4.hpp"
#include <numbers>
#include "../Scene/Transform.hpp"

int main()
{
    Engine engine;

    engine.initialize();
    engine.run();
    engine.shutdown();

    Transform transform;
    transform.position = Vector3(10,0,0);
    transform.rotation = Vector3(0,0,0);
    transform.scale = Vector3(1,1,1);

    Matrix4 test = transform.getModelMatrix();
    test.print();

    return 0;
}