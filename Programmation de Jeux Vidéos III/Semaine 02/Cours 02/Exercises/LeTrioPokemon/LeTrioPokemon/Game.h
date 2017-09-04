#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Pokemon.h"
#include "Pokeball.h"
#include "InputManager.h"

using namespace sf;

class Game
{
public:
	Game();
	int run();
	int testTest();

private:
    int nbPoints;

	const int LARGEUR = 1280;
	const int HAUTEUR = 720;

	bool init();
	void getInputs();
	void update();
	void draw();

	RenderWindow mainWin;
	View view;
	Event event;
    Pokemon pokemon;
    Pokeball pokeball;
    InputManager inputManager;
};