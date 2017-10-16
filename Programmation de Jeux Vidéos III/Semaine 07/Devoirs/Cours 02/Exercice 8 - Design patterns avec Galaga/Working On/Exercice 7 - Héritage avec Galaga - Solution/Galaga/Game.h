#pragma once

#include <SFML/Graphics.hpp>
#include "Galaga.h"
#include "Spawner.h"
#include <vector>
#include "FabriqueGalaga.h"
#include "Player.h"
#include <random>

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

		RenderWindow mainWin;
		View view;
		Event event;

		Sprite background;
		Texture backgroundT;

		//Notre tableau de pointeurs de la super-classe
		std::vector<Galaga*> galagas;
        /*Les spawners*/
        int nbSpawners = 2;
        Spawner spawners[2];
        bool right[2];
        /*Le joueur*/
        Player* player = Player::GetInstance();
		bool init();
		void getInputs();
		void update();
		void draw();
		
        //Notre générateur de chiffres aléatoires
        std::default_random_engine generator;
        //Méthode pour la création de galagas sur un de nos spawners
        Galaga* CreateGalaga(FabriqueGalaga::Galagas type);
		//Nouveau à présent qu'on utilise les pointeurs, on va tout libérer avant de terminer
		void unload();
	};
}