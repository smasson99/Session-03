#pragma once

#include <SFML/Graphics.hpp>

class Background
{
public:
    int START_WIDTH;
    int START_HEIGHT;
    Background();
    void SetScale(int width, int height);
    void Draw(sf::RenderWindow&);
    bool Init(sf::RenderWindow&);
private:
    sf::Sprite sprite;
    sf::Texture spriteTexture;
};