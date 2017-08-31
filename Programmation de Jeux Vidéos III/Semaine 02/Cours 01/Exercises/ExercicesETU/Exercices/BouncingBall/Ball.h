#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
public:
    Ball();
    void SetAngle(float newAngle);
    void SetRadius(float newRadius);
    void Update(sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window);
    void SetPosition(float x, float y);
    bool Init();
private:
    float radius;
    float angle;
    sf::Sprite sprite;
    sf::Texture ballTexture;
    sf::Vector2f dirrection;
};