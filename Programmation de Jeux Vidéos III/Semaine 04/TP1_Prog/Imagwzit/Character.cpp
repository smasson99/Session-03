#define _USE_MATH_DEFINES
#include <cmath> 
#include <math.h>
#include "Character.h"
#include <iostream>

bool Character::Init(std::string path)
{
    bool result = texture.loadFromFile(path);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x, texture.getSize().y);
    return result;
}

Character::Character()
{
    //Initialiser les variables par défaut
    targetPos.x = 1;
    targetPos.y = 0;
}

void Character::SetPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

void Character::UpdateTargetPosistion(float x, float y)
{
    targetPos = sf::Vector2f(x, y);
}

void Character::LookAtTarget()
{
    float angle = atan2f((targetPos.y - sprite.getPosition().y), (targetPos.x - sprite.getPosition().x));
    angle = angle * (180 / M_PI);
    if (angle < 0)
    {
        angle = 360 + (angle);
    }
    std::cout << "X: " << targetPos.x << " Y: " << targetPos.y << " angleRes: " << angle << std::endl;
    sprite.setRotation(angle);
}