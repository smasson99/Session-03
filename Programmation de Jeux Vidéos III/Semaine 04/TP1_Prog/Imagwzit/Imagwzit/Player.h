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
    bool IsImmortal();
    float GetAngle();
    void Update(float x, float y);
    Projectile CreateProjectile();
    int GetHealthPoints() const;
    void Hit();
    void AddHealthPoints(int nb);
private:
    int nbHealthPoints;
    sf::Clock shootClock;
    sf::Clock immortalClock;
    sf::Time shootDelay;
    sf::Time immortalDelay;
    bool isHit;

};

#endif // !PLAYER_H
