#pragma once
#include "Character.h"

class Zombie :public Character
{
protected:
public:
    Zombie();
    void Update(float playerX, float playerY);
    void SetEnabled(bool enable, float x, float y);
    bool IsEnable() const;
private:
    bool enable;
    sf::Vector2f dir;
    float speed;
};