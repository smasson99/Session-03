#include "Player.h"

Player::Player()
{
    //Initialisation des varaibles par défaut
    nbHealthPoints = 5;
    shootDelay = sf::seconds(0.15f);
    immortalDelay = sf::seconds(3.0f);
    isHit = false;
}

bool Player::CanFire()
{
    if (!isHit && shootClock.getElapsedTime().asSeconds() > shootDelay.asSeconds())
    {
        shootClock.restart();
        return true;
    }
    else
    {
        return false;
    }
}

bool Player::IsImmortal()
{
    return isHit;
}

float Player::GetAngle()
{
    return currentAngle;
}

void Player::Update(float x, float y)
{
    //Mettre à jour la position de de la cible
    UpdateTargetPosistion(x, y);
    //S'assurer de pointer vers la cible (qui dans ce cas-ci devrait être la souris)
    LookAtTarget();
    //Dans le cas où le joueur a été touché et que son temps de répit est passé
    if (isHit && immortalClock.getElapsedTime().asSeconds() > immortalDelay.asSeconds())
    {
        //Rendre mortel
        isHit = false;
        SetTransparencyAlpha(255.0f);
    }
}

Projectile Player::CreateProjectile()
{
    //Retourner un projectile selon le standard
    return Projectile(GetX(), GetY(), currentAngle, false);
}

int Player::GetHealthPoints() const
{
    return nbHealthPoints;
}

void Player::Hit()
{
    if (nbHealthPoints > 0)
        nbHealthPoints--;
    isHit = true;
    SetTransparencyAlpha(255.0f/2);
    immortalClock.restart();
}

void Player::AddHealthPoints(int nb)
{
    nbHealthPoints += nb;
}

