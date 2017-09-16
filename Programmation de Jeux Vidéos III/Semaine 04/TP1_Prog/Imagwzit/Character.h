#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML\Graphics.hpp>
#include <iostream>

class Character
{
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f targetPos;
    bool Init(std::string path);
    Character();
    float ToDegree(float radians);
    void UpdateTargetPosistion(float x, float y);
public:
    void SetPosition(float x, float y);
    sf::Sprite GetSprite() const
    {
        return sprite;
    }
    void LookAtTarget();
private:
};

#endif // !CHARACTER_H
