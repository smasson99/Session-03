#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "InputManager.h"
// Pour simplifier l'acc�s aux �l�ments SFML
using namespace sf;

class Game
{
public:
	Game();
	int run();

private:
  // Petite modification sur le mod�le de projet ici
  // pour montrer la d�claration de propri�t�s statiques
	static const int LARGEUR;
	static const int HAUTEUR;

	bool init();
	void getInputs();
	void update();
	void draw();

	RenderWindow mainWin;
	View view;
	Event event;

  InputManager inputManager;

  sf::Texture background;
  sf::Sprite backgroundSprite;

  sf::Texture ball;
  sf::Sprite ballSprite;

  sf::Music music;

  sf::Font font;
  sf::Text text;


};