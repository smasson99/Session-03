#include "Projectile.h"

Projectile::Projectile(float x, float y, float angle, bool isRadian)
{
    enable = false;
    this->angle = angle;
    this->isRadian = isRadian;
    SetRotation(angle, isRadian);
    speed = 20.0f;
    Movable::SetPosition(x, y);
    dir = Movable::GenerateDirection(angle, isRadian);
}

void Projectile::Update()
{
    SetPosition(GetX()+(dir.x*speed), GetY()+(dir.y*speed));
}

void Projectile::SetEnable(bool enable, sf::Vector2f startPos, float angle)
{
    this->enable = enable;
    this->angle = angle;
    SetRotation(angle, isRadian);
    SetPosition(startPos.x, startPos.y);
    dir = Movable::GenerateDirection(angle, isRadian);
}

bool Projectile::IsEnable()
{
    return enable;
}
