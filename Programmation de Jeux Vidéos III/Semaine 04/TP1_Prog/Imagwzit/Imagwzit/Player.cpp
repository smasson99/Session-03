#include "Player.h"

Player::Player()
{
    //Initialisation des varaibles par d�faut
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
    //Mettre � jour la position de de la cible
    UpdateTargetPosistion(x, y);
    //S'assurer de pointer vers la cible (qui dans ce cas-ci devrait �tre la souris)
    LookAtTarget();
    //Dans le cas o� le joueur a �t� touch� et que son temps de r�pit est pass�
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

