#include "Engine.hpp"
#include "Time.hpp"
#include <iostream>

Engine::Engine()
{
    running = false;

    std::cout << "Construction du moteur" << std::endl;
}

void Engine::initialize()
{
    std::cout << "Initialisation du moteur" << std::endl;

    running = true;
}

void Engine::run()
{
    while (running)
    {
        update();
        render();

//limitée a 10 iter pour le test
        static int frameCount = 0;
        frameCount++;

        if (frameCount >= 10)
        {
            running = false;
        }
    }
}

void Engine::update()
{
    Time::update();

    float dt = Time::deltaTime();

    Vector3 direction(1.0f, 0.0f, 1.0f);

player.move(direction, 2.0f, dt);

    Vector3 position = player.getPosition();

    std::cout << "Position du joueur : "
            << position.x << ", "
            << position.y << ", "
            << position.z
            << std::endl;
}

void Engine::render()
{
    std::cout << "Rendu de l'image" << std::endl;
}

void Engine::shutdown()
{
    std::cout << "Arret du moteur" << std::endl;
}