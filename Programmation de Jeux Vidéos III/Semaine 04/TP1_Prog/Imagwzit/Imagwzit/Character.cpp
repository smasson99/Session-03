#include "Character.h"

Character::Character()
{
    //Initialiser les variables par défaut
    targetPos.x = 1;
    targetPos.y = 0;
}

void Character::SetPosition(float x, float y)
{
    Movable::SetPosition(x, y);
}

void Character::UpdateTargetPosistion(float x, float y)
{
    targetPos = sf::Vector2f(x, y);
}

void Character::LookAtTarget()
{
    float angle = (float)atan2((targetPos.y - GetY()), (targetPos.x - GetX()));
    currentAngle = Movable::SetRotation(angle, true);
}