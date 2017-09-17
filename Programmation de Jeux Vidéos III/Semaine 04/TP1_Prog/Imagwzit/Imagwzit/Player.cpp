#include "Player.h"

Player::Player()
{
    //Initialisation des varaibles par défaut
}

//void Player::Fire()
//{
//    
//}

void Player::Update(float x, float y)
{
    //Mettre à jour la position de de la cible
    UpdateTargetPosistion(x, y);
    //S'assurer de pointer vers la cible (qui dans ce cas-ci devrait être la souris)
    LookAtTarget();
}

Projectile Player::CreateProjectile()
{
    //Retourner un projectile selon le standard
    return Projectile(GetX(), GetY(), currentAngle, false);
}
