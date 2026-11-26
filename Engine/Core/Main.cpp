#include "Engine.hpp"

int main()
{
    Engine engine;

    engine.initialize();
    engine.run();
    engine.shutdown();

    return 0;
}