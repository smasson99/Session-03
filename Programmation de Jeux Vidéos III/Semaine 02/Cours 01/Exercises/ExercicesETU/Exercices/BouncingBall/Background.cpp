#include "Background.h"

Background::Background()
{
    spriteTexture.loadFromFile("Assets\\Sprites\\terrain.png");
}

bool Background::Init(sf::RenderWindow& window)
{
    START_WIDTH = window.getSize().x;
    START_HEIGHT = window.getSize().y;
    sprite.setTexture(spriteTexture);
    SetScale(START_WIDTH, START_HEIGHT);
    return spriteTexture.loadFromFile("Assets\\Sprites\\terrain.png");
}

void Background::SetScale(int width, int height)
{
    sprite.setScale(width / sprite.getLocalBounds().width, height / sprite.getLocalBounds().height);
}

void Background::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}