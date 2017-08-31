#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "SFMLCircle.h"
#include "InputManager.h"
// Pour simplifier l'accès aux éléments SFML
using namespace sf;

class Game
{
public:
	Game();
	int run();

private:
  // Petite modification sur le modèle de projet ici
  // pour montrer la déclaration de propriétés statiques
	static const int LARGEUR;
	static const int HAUTEUR;

	bool init();
	void getInputs();
	void update();
	void draw();

	RenderWindow mainWin;
	View view;
	Event event;

  // Le cercle à afficher
  sf::Color xboxColors[4];
  sf::Vector2f circleOffset;
  SFMLCircle circle;
  InputManager inputManager;
};