#include "Player.h"

bool Player::Init()
{
    return Character::Init("Sprites\\FreeArt\\Joueur.png");
}

Player::Player()
{

}

void Player::Update(float x, float y)
{
    UpdateTargetPosistion(x, y);
    LookAtTarget();
}