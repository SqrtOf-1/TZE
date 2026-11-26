#pragma once

#include "../Math/Vector3.hpp"

class Player {
public:
    Player();

    void move(const Vector3& direction, float speed, float dt);

    Vector3 getPosition() const;

private:
    Vector3 position;
};