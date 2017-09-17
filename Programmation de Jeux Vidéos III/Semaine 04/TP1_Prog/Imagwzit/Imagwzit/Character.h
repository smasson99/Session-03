#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H
#include "Movable.h"

class Character:public Movable
{
protected:
    float currentAngle;
    sf::Vector2f targetPos;
    Character();
    void UpdateTargetPosistion(float x, float y);
public:
    void SetPosition(float x, float y);
    void LookAtTarget();
private:
};

#endif // !CHARACTER_H
