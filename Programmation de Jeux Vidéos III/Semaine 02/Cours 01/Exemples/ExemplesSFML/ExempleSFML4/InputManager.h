#pragma once

// On aurait pu inclure <SFML/Graphics.hpp> ici mais il est 
// suffisant de faire
namespace sf
{
  class RenderWindow;
}
// Quelqu'un peut me dire pourquoi ???? En passant, c'est une question difficile...

enum Direction
{
  Up,
  Down,
  Left, 
  Right,
};

class InputManager
{
public:
  InputManager();
  void Clear();
  void Update(sf::RenderWindow& mainWin);

  bool GetUp();
  bool GetDown();
  bool GetLeft();
  bool GetRight();

  bool GetButtons(int button);

  float GetAxeX();
  float GetAxeY();

  float GetMouseX();
  float GetMouseY();
  bool GetMouseClick();


private:
  float noise;
  float axeX;
  float axeY;

  bool buttons[4];
  bool directionalKeys[4];

  float mouseX;
  float mouseY;
  bool mouseClick;

};
