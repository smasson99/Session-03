#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace galaga
{
	class Player : public Sprite
	{
	public:
		//ATTENTION: �tant donn� la nature du pattern Singleton, le seul constructeur sous ce pattern devrait toujours �tre
		//un constructeur par d�faut, puisque getInstance ne devrait jamais avoir de param�tre. Une fois l'instance
		//cr��e pour la premi�re fois, il faut l'initialiser avec une m�thode "initialiser" � qui on passe tous les 
		//param�tres du constructeur original.

        static Player * GetInstance();
        ~Player();
        void Initialiser(const float posX, const float posY, const float vitesse, RenderWindow * renderWindow);
		bool chargerTexture(const char texturePath[]);
		void deplacement(const bool aDroite); //Le joueur ne peut se d�placer � gauche ou � droite, Un simple bool est donc suffisant.
        int GetLimiteDroite();
        int GetLimiteGauche();
	private:
        Player();
        static Player * instance;
		RenderWindow* renderWindow;	//Pointeur sur la fen�tre.  pratique pour connaitre sa taille entre autre
		Texture texture;    //Puisque le joueur sera unique, la texture n'a pas besoin d'�tre statique.
		float vitesse;      //Vitesse de d�placement du player.  8 dans l'exemple pr�sent�.
        int limiteGauche;   //Limites de d�placement par rapport � l'�cran; pratique � garder pour ne pas les recalculer � chaque fois.
		int limiteDroite;
	};
}

