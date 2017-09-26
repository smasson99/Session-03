#define _USE_MATH_DEFINES
#include <cmath>
#include "Movable.h"


Movable::Movable()
{
    //Initialisation des valeurs par défaut
    SetPosition(0, 0);
    speed = 10.0f;
}

bool Movable::Init(std::string path)
{
    //Loading des textures
    bool result = texture.loadFromFile(path);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    //Initialiser les collisions en fonction de la texture
    sphereCollider.SetRayon(texture.getSize().x / 2);
    sphereCollider.SetPosition(sprite.getPosition().x, sprite.getPosition().y);
    //Retourner le résultat de l'opération de chargement
    return result;
}

void Movable::SetPosition(float x, float y)
{
    sprite.setPosition(x, y);
    sphereCollider.SetPosition(x, y);
}

void Movable::SetSpeed(float newSpeed)
{
    speed = newSpeed;
}

void Movable::aScaleFrom(float scaleAddition)
{
    sprite.setScale(sprite.getScale().x + scaleAddition, sprite.getScale().y + scaleAddition);
    sphereCollider.SetRayon(texture.getSize().x + texture.getSize().x*(1/sprite.getScale().x));
}

void Movable::SetTransparencyAlpha(float transparency)
{
    sprite.setColor(sf::Color(sprite.getColor().r, sprite.getColor().g, sprite.getColor().b, 
        transparency));
}

void Movable::ResetScale()
{
    sprite.setScale(1, 1);
    sphereCollider.SetRayon(texture.getSize().x / 2);
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
    return sprite.getPosition();
}

float Movable::GetX() const
{
    return sprite.getPosition().x;
}

float Movable::GetY() const
{
    return sprite.getPosition().y;
}

void Movable::Draw(sf::RenderWindow & mainWin)
{
    mainWin.draw(sprite);
}

CollisionSphere Movable::GetCollider() const
{
    return sphereCollider;
}

sf::Texture Movable::GetTexture()
{
    return texture;
}

float Movable::ToDegree(float radians) const
{
    return radians *(180/M_PI);
}

float Movable::ToRadian(float degrees) const
{
    return degrees *(M_PI / 180);
}