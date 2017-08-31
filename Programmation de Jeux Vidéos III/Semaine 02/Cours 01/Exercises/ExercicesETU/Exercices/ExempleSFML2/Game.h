#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "SFMLCircle.h"

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

  // Le cercle � afficher
  SFMLCircle circle;
};