#pragma once
#ifndef MOVABLE_H
#define MOVABLE_H
#include <iostream>
#include <SFML\Graphics.hpp>

class Movable
{
protected:
public:
    Movable();
    bool Init(std::string path);
    void SetPosition(float x, float y);
    void MultiplySizeFrom(float multiplicator);
    float SetRotation(float deg, bool isRandian);
    sf::Vector2f GenerateDirection(float angle, bool isRadian);
    sf::Vector2f GetPosition() const;
    float GetX() const;
    float GetY() const;
    void Draw(sf::RenderWindow& mainWin);
private:
    float posX;
    float posY;
    float ToDegree(float radians) const;
    float ToRadian(float degrees) const;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f direction;
};

#endif // !MOVABLE_H
