#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player:public Character
{
protected:
public:
    bool Init();
    Player();
    void Update(float x, float y);
private:
};

#endif // !PLAYER_H
