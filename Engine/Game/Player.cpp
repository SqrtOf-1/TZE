#include "Player.hpp"

Player::Player()
{
    position = Vector3(0.0f, 0.0f, 0.0f);
}

void Player::move(const Vector3& direction, float speed, float dt)
{
    Vector3 movement = direction.normalized() * speed * dt;

    position = position + movement;
}

Vector3 Player::getPosition() const
{
    return position;
}