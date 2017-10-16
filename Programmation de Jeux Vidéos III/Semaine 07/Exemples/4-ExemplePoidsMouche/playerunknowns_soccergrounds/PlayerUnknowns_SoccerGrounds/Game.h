#pragma once
#define _USE_MATH_DEFINES
#include <vld.h>
#include <ctime>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Balle.h"
#include "Game.h"

//using namespace sf;
namespace pusg
{
	class Game
	{
	public:
		Game();
		int run();

	private:
		const int LARGEUR = 1302;
		const int HAUTEUR = 666;

		Sprite terrain;
		Texture terrainT;

		Sprite soccerBall;
		Texture soccerBallT;

		Font font;
		Text text;

		std::vector<Balle*> balles;
		bool clicked = false;
		bool droitDeFaireFeu = true;

		bool init();
		void getInputs();
		void update();
		void draw();
		void unload();

		void gererClick();
		void gererMouvementBalles();
		void gererCollisionsBalles();
		void gererEffacementBalles();

		void ecrireGrosTexte(String texte, int posX, int posY);

		RenderWindow mainWin;
		View view;
		Event event;
	};
}