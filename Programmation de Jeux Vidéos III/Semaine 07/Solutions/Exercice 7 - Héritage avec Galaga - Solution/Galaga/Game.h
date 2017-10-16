#pragma once

#include <SFML/Graphics.hpp>
#include "Galaga.h"

using namespace sf;

namespace galaga
{
	class Game
	{
	public:
		Game();
		int run();

	private:
		const int LARGEUR = 1280;
		const int HAUTEUR = 796;
		const int VITESSE = 7;

		//Nombre d'animations et frames par animation qu'on a dans notre spriteSheet.
		const int NOMBRE_ANIMATIONS = 3;
		const int NOMBRE_FRAMES = 2;

		//Enum des sprites de Galaga, selon leurs positions dans la sheet
		enum Galagas{ WASP, BUTTERFLY, CATCHER };

		RenderWindow mainWin;
		View view;
		Event event;

		Sprite background;
		Texture backgroundT;

		//Notre tableau de pointeurs de la super-classe
		Galaga * Galagas[3];

		bool init();
		void getInputs();
		void update();
		void draw();
		
		//Nouveau à présent qu'on utilise les pointeurs, on va tout libérer avant de terminer
		void unload();
	};
}