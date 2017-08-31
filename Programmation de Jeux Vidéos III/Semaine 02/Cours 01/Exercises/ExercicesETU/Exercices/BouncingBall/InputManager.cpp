#include "InputManager.h"
#include <SFML/Graphics.hpp>

InputManager::InputManager()
{
  Clear();
}

void InputManager::Update(sf::RenderWindow& mainWin)
{
  Clear();
  ////------------Gamepad---------------------------------------------------------------------
  for (int i = 0; i < 4; i++)
  {
    buttons[i] = sf::Joystick::isButtonPressed(0, i);
  }

  axeX = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);
  axeY = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y);

  //------------Clavier---------------------------------------------------------------------
  directionalKeys[Up] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
  directionalKeys[Down] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
  directionalKeys[Left] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
  directionalKeys[Right] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

  //------------Souris---------------------------------------------------------------------
  mouseX = (float)sf::Mouse::getPosition(mainWin).x;
  mouseY = (float)sf::Mouse::getPosition(mainWin).y;
  mouseClick = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool InputManager::GetUp()
{
  // Attention: notez la différence avec C#: pas de Direction.Up
  return directionalKeys[Up];
}
bool InputManager::GetDown()
{
  return directionalKeys[Down];
}

void InputManager::Clear()
{
  noise = 0;
  axeX = 0;
  axeY = 0;

  for (int i = 0;i<4;i++)
  {
    buttons[i] = false;
    directionalKeys[i] = false;
  }
  mouseX = 0;
  mouseY = 0;
  mouseClick = false;
}
bool InputManager::GetLeft()
{
  return directionalKeys[Left];
}
bool InputManager::GetRight()
{
  return directionalKeys[Right];
}

bool InputManager::GetButtons(int button)
{
  return buttons[button];
}

float InputManager::GetAxeX()
{
  return axeX;
}
float InputManager::GetAxeY()
{
  return axeY;
}

float InputManager::GetMouseX()
{
  return mouseX;
}
float InputManager::GetMouseY()
{
  return mouseY;
}
bool InputManager::GetMouseClick()
{
  return mouseClick;
}