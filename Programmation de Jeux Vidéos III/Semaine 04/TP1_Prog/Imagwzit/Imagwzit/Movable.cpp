#define _USE_MATH_DEFINES
#include <cmath>
#include "Movable.h"


Movable::Movable()
{
    //Initialisation des valeurs par défaut
    posX = 0.00f;
    posY = 0.00f;
}

bool Movable::Init(std::string path)
{
    //Loading des textures
    bool result = texture.loadFromFile(path);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    //Initialiser les collisions en fonction de la texture
    sphereCollider.SetRayon(texture.getSize().x / 2);
    sphereCollider.SetPosition(posX, posY);
    //Retourner le résultat de l'opération de chargement
    return result;
}

void Movable::SetPosition(float x, float y)
{
    posX = x;
    posY = y;
    sprite.setPosition(posX, posY);
    sphereCollider.SetPosition(posX, posY);
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

float Movable::GetX() const
{
    return posX;
}

float Movable::GetY() const
{
    return posY;
}

void Movable::Draw(sf::RenderWindow & mainWin)
{
    mainWin.draw(sprite);
}

CollisionSphere Movable::GetCollider() const
{
    return sphereCollider;
}

float Movable::ToDegree(float radians) const
{
    return radians *(180/M_PI);
}

float Movable::ToRadian(float degrees) const
{
    return degrees *(M_PI / 180);
}