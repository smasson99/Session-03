#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace galaga
{
	class Player : public Sprite
	{
	public:
		//ATTENTION: Étant donné la nature du pattern Singleton, le seul constructeur sous ce pattern devrait toujours être
		//un constructeur par défaut, puisque getInstance ne devrait jamais avoir de paramètre. Une fois l'instance
		//créée pour la première fois, il faut l'initialiser avec une méthode "initialiser" à qui on passe tous les 
		//paramètres du constructeur original.

        static Player * GetInstance();
        ~Player();
        void Initialiser(const float posX, const float posY, const float vitesse, RenderWindow * renderWindow);
		bool chargerTexture(const char texturePath[]);
		void deplacement(const bool aDroite); //Le joueur ne peut se déplacer à gauche ou à droite, Un simple bool est donc suffisant.
        int GetLimiteDroite();
        int GetLimiteGauche();
	private:
        Player();
        static Player * instance;
		RenderWindow* renderWindow;	//Pointeur sur la fenêtre.  pratique pour connaitre sa taille entre autre
		Texture texture;    //Puisque le joueur sera unique, la texture n'a pas besoin d'être statique.
		float vitesse;      //Vitesse de déplacement du player.  8 dans l'exemple présenté.
        int limiteGauche;   //Limites de déplacement par rapport à l'écran; pratique à garder pour ne pas les recalculer à chaque fois.
		int limiteDroite;
	};
}

