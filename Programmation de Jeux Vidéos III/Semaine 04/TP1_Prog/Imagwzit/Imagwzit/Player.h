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
    bool CanFire();
    float GetAngle();
    void Update(float x, float y);
    Projectile CreateProjectile();
    int GetHealthPoints() const;
    void Hit();
private:
    int nbHealthPoints;
    float cadence;
    sf::Clock clock;
    sf::Time time;
};

#endif // !PLAYER_H
