#include "Spawner.h"

using namespace galaga;

Spawner::Spawner()
{
    myCircleShape.setRadius(RAYON);
    myCircleShape.setOutlineThickness(TICKNESS);
    myCircleShape.setFillColor(sf::Color::Transparent);
}

void Spawner::SetPosition(float x, float y)
{
    myCircleShape.setPosition(x, y);
}

void Spawner::Draw(sf::RenderWindow & mainWin)
{
    mainWin.draw(myCircleShape);
}

float Spawner::GetDisplacement()
{
    return DISPLACEMENT;
}

void galaga::Spawner::AutoMoveX(bool right)
{
    if (right)
        myCircleShape.move(sf::Vector2f(DISPLACEMENT, 0));
    else
        myCircleShape.move(sf::Vector2f(-DISPLACEMENT, 0));
}

float Spawner::GetX()
{
    return myCircleShape.getPosition().x;
}

float Spawner::GetY()
{
    return myCircleShape.getPosition().y;
}
