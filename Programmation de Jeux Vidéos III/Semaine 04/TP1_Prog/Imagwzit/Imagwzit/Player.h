#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Projectile.h"

class Player:public Character
{
protected:
public:
    Player();
    /*void Fire();*/
    void Update(float x, float y);
    Projectile CreateProjectile();
private:
};

#endif // !PLAYER_H
