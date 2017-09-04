#pragma once

namespace sf
{
	class RenderWindow;
}

enum Dirrection
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class InputManager
{
public:
	InputManager();
	void Update(sf::RenderWindow& mainWin);
	void Clear();
	float GetMouseX();
	float GetMouseY();
    bool GetMouseClicked();
	bool GetButtons();

private:
	float noise;
	float axeX;
	float axeY;

	float mouseX;
	float mouseY;

	bool buttons[4];
	bool directionalKeys[4];

	bool mouseClick;
};