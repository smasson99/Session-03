#pragma once
#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Movable.h"

class Projectile:public Movable
{
protected:
public:
    Projectile(float x, float y, float angle, bool isRadian);
    void Update();
private:
    float angle;
    float speed;
    bool isRadian;
    sf::Vector2f dir;
};

#endif // !PROJECTILE_H
