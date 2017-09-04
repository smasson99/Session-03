#include "InputManager.h"
#include <SFML\Graphics.hpp>

InputManager::InputManager()
{
	Clear();
}

void InputManager::Update(sf::RenderWindow& mainWindow)
{
	Clear();

	//---Souris
	mouseX = (float)sf::Mouse::getPosition(mainWindow).x;
	mouseY = (float)sf::Mouse::getPosition(mainWindow).y;
	mouseClick = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

void InputManager::Clear()
{
	mouseX = 0.00f;
	mouseY = 0.00f;

	mouseClick = false;
}

float InputManager::GetMouseX()
{
    return mouseX;
}

float InputManager::GetMouseY()
{
    return mouseY;
}

bool InputManager::GetMouseClicked()
{
    return mouseClick;
}