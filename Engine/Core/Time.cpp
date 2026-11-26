#include "Time.hpp"
#include <chrono>

using Clock = std::chrono::steady_clock;

static auto lastFrameTime = Clock::now();

float Time::currentDeltaTime = 0.0f;

void Time::update()
{

    auto currentTime = Clock::now();

    std::chrono::duration<float> elapsedTime =
        currentTime - lastFrameTime;
    currentDeltaTime = elapsedTime.count();
    lastFrameTime = currentTime;
}

float Time::deltaTime()
{
    return currentDeltaTime;
}