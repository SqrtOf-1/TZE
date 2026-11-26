#pragma once
#include "../Game/Player.hpp"

class Engine {
public:
    Engine();

    void initialize();
    void run();
    void update();
    void render();
    void shutdown();

private:
    bool running;
    Player player;
};