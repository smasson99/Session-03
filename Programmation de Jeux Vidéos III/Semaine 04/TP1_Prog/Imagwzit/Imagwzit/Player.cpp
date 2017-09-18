#include "Player.h"

Player::Player()
{
    //Initialisation des varaibles par d�faut
    cadence = 0.15f;
    time = sf::seconds(cadence);
    clock.restart();
}

bool Player::CanFire()
{
    if (clock.getElapsedTime().asSeconds() > time.asSeconds())
    {
        clock.restart();
        return true;
    }
    else
    {
        return false;
    }
}

float Player::GetAngle()
{
    return currentAngle;
}

void Player::Update(float x, float y)
{
    //Mettre � jour la position de de la cible
    UpdateTargetPosistion(x, y);
    //S'assurer de pointer vers la cible (qui dans ce cas-ci devrait �tre la souris)
    LookAtTarget();
}

Projectile Player::CreateProjectile()
{
    //Retourner un projectile selon le standard
    return Projectile(GetX(), GetY(), currentAngle, false);
}
