#include "Zombie.h"

Zombie::Zombie()
{
    //Initialisation des variables par défaut
    enable = false;
    speed = 1.0f;
}

void Zombie::Update(float playerX, float playerY)
{
    //Mettre à jour la position de de la cible
    UpdateTargetPosistion(playerX, playerY);
    //S'assurer de pointer vers la cible (qui dans ce cas-ci devrait être la souris)
    LookAtTarget();
    dir = GenerateDirection(currentAngle, false);
    SetPosition(GetX() + (dir.x*speed), GetY() + (dir.y*speed));
}

void Zombie::SetEnabled(bool enable, float x, float y)
{
    this->enable = enable;
    SetPosition(x, y);
}

bool Zombie::IsEnable() const
{
    return enable;
}
