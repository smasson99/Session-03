#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace galaga
{
	class Player : public Sprite
	{
	public:
		static Player *getInstance();
		static void release();

		void initialiser(const float posX, const float posY, const float vitesse, RenderWindow* const renderWindow);
		bool chargerTexture(const char texturePath[]);
		void deplacement(const bool aDroite);

	private:
		static Player *instance;
		Player();
		void ajustementsVisuels();

		Player(const Player&);
		void operator=(const Player&);

		RenderWindow* renderWindow;	//Pointeur sur la fenêtre.  pratique pour connaitre sa taille entre autre
		float vitesse;  //Vitesse de déplacement du player
		int limiteGauche;
		int limiteDroite;
		Texture texture;
	};
}

