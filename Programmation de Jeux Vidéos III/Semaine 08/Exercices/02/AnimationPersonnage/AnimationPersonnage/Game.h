#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include "Personnage.h"

using namespace sf;

namespace isometrique
{
	class Game
	{
	public:
		Game();
		int run();

	private:
		const int LARGEUR = 1024;
		const int HAUTEUR = 768;

		bool init();
		void getInputs();
		void update();
		void draw();

		RenderWindow mainWin;
		View view;
		Event event;

		Sprite background;  //On utilise un seul sprite pour la tuile, qu'on va �tamper 18 fois.
		Texture backgroundT;
		Vector2f backgroundPositions[18]; //Pour avoir un beau plancher on a besoin de 18 tuiles plac�s un peu � l'oeil

		//Ici puisqu'on va travailler en polymorphisme, aussi bien s'adapter et commencer � travailler en pointeur.
		//Toujours n�cessaire pour le constuire apr�s qu'on ai charg� les textures
		Personnage * personnage;
	};
}