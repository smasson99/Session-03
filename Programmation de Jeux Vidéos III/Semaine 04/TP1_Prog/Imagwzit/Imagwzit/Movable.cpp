#define _USE_MATH_DEFINES
#include <cmath>
#include "Movable.h"


Movable::Movable()
{
    posX = 0.00f;
    posY = 0.00f;
}

bool Movable::Init(std::string path)
{
    bool result = texture.loadFromFile(path);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    return result;
}

void Movable::SetPosition(float x, float y)
{
    posX = x;
    posY = y;
    sprite.setPosition(posX, posY);
}

float Movable::SetRotation(float unit, bool isRadian)
{
    if (isRadian)
        unit = ToDegree(unit);
    if (unit < 0)
        unit += 360.0f;
    sprite.setRotation(unit);
    return unit;
}

sf::Vector2f Movable::GenerateDirection(float angle, bool isRadian)
{
    if (!isRadian)
        angle = ToRadian(angle);
    direction.x = cos(angle);
    direction.y = sin(angle);
    return direction;
}

sf::Vector2f Movable::GetPosition() const
{
    return sf::Vector2f(posX, posY);
}

sf::Sprite Movable::GetSprite() const
{
    return sprite;
}

float Movable::GetX() const
{
    return posX;
}

float Movable::GetY() const
{
    return posY;
}

float Movable::ToDegree(float radians) const
{
    return radians *(180/M_PI);
}

float Movable::ToRadian(float degrees) const
{
    return degrees *(M_PI / 180);
}