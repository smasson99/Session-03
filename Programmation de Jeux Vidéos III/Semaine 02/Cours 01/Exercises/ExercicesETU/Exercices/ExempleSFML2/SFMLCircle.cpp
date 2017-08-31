#include "SFMLCircle.h"

SFMLCircle::SFMLCircle()
{
  // Grosseur par d�faut du cercle: 1
  shape = sf::CircleShape(1.0f);
  SetRadius(1.0f);  
}

SFMLCircle::SFMLCircle(float radius)
{
  // Lorsqu'un param�tre porte le m�me nom qu'une propri�t�,
  // on doit utiliser this-> (et non this. comme en C#) pour 
  // r�f�rencer la propri�t� de l'objet courant (qu'on appelera
  // pour le reste du cours le "param�tre implicite)
  this->radius = radius;

  shape = sf::CircleShape(radius);
  SetRadius(radius);
}

void SFMLCircle::SetBackgroundColor(sf::Color color)
{
  shape.setFillColor(color);
}

void SFMLCircle::SetOutlineColor(sf::Color color)
{
  shape.setOutlineColor(color);
}

void SFMLCircle::SetRadius(float radius)
{
  shape.setRadius(radius);
  shape.setOrigin(sf::Vector2f(radius, radius));
}

sf::Vector2f SFMLCircle::GetPosition()
{
  return shape.getPosition();
}

void SFMLCircle::SetPosition(float x, float y)
{
  shape.setPosition(sf::Vector2f(x,y));
}

void SFMLCircle::SetPosition(sf::Vector2f& pos)
{
  shape.setPosition(pos);
}

void SFMLCircle::Draw(sf::RenderWindow& window)
{
  window.draw(shape);
}