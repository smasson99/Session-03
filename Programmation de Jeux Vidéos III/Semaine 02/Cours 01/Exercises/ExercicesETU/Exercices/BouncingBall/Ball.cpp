#include "Ball.h"
#include <stdlib.h>
#include <cmath>
#include <time.h>

//class Ball
//{
//public:
//    Ball(float radius, float angle);
//    float SetAngle(float newAngle);
//    float SetRadius(float newRadius);
//
//private:
//    float radius;
//    float angle;
//    sf::CircleShape shape;
//};

bool Ball::Init()
{
    sprite.setTexture(ballTexture);
    SetAngle(angle + 45);
    return ballTexture.loadFromFile("Assets\\Sprites\\soccerBall.png");
}

Ball::Ball()
{
    ballTexture.loadFromFile("Assets\\Sprites\\soccerBall.png");
    this->angle = 45.00f;
    this->radius = 50.00f;
}

void Ball::SetAngle(float newAngle)
{
    angle = newAngle;
    if (angle > 360)
    {
        angle -= 360;
    }
    else if (angle < 0)
    {
        angle += 360;
    }
    dirrection = sf::Vector2f(cos(angle), sin(angle));
}
void Ball::SetRadius(float newRadius)
{
    radius = newRadius;
}
void Ball::SetPosition(float x, float y)
{
    sprite.setPosition(sf::Vector2f(x, y));
}
void Ball::Update(sf::RenderWindow& window)
{
    float angleChange = 90.00f;
    sprite.move(dirrection * 5.75f);
    //Vérifier qu'on ne sort pas des limittes du tableau. Autrement, changer l'angle.
    if (sprite.getPosition().x <= 0 || sprite.getPosition().y <= 0 || sprite.getPosition().x 
    >= window.getSize().x || sprite.getPosition().y >= window.getSize().y)
    {
        if (angle >= 0 && angle <= 90)
        {
            if (sprite.getPosition().x >= window.getSize().x-30)
            {
                SetAngle(angle + angleChange);
            }
            else
            {
                SetAngle(angle - angleChange);
            }
        }
        else if (angle > 90 && angle <= 180)
        {
            if (sprite.getPosition().x <= 30)
            {
                SetAngle(angle + angleChange);
            }
            else
            {
                SetAngle(angle - angleChange);
            }
        }
        else if (angle > 180 && angle <= 270)
        {
            if (sprite.getPosition().x <= 30)
            {
                SetAngle(angle + angleChange);
            }
            else
            {
                SetAngle(angle - angleChange);
            }
        }
        else if (angle > 270 && angle <= 360)
        {
            if (sprite.getPosition().x >= window.getSize().x-30)
            {
                SetAngle(angle - angleChange);
            }
            else
            {
                SetAngle(angle + angleChange);
            }
        }
    }
}
void Ball::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
