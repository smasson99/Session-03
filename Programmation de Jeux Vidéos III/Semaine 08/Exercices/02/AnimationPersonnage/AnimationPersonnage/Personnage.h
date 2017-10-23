#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>

using namespace sf;

namespace isometrique
{
	class Personnage : public Sprite
	{
	public:		
		//Constructeur avec tous les attributs plus haut.  Utiliser un tableau de char pour le path évite d'inclure string et un string a un constructeur avec un tableau de char
		Personnage(const float posX, const float posY, RenderWindow* const renderWindow);
		~Personnage();

		static bool chargerTextures(const char texturePath[]);		
		void ajustementsVisuels(); //Méthode de "finalisation du constructeur"
		void deplacement();// (const float axeX, const float axeY);
		void gererInputs();

	private:
		//Méthode pour le passage d'un côté à l'autre de l'écran
		float autreCote(float positionDansAxe, const int tailleEcran, const int demiTailleVaisseau);
		void keyboardMovement();
		void joystickMovement();
        void UpdateAnim(const int& cadranCourant, const float& frameCouranteP, IntRect** myRect);
		float eliminateVibration(float analogInput);

		//ordre des niveau d'animation dans la texture
		const enum DIRECTIONS { GAUCHE, GAUCHE_HAUT, HAUT, DROITE_HAUT, DROITE, DROITE_BAS, BAS, GAUCHE_BAS };

		const int VITESSE = 5; //Vitesse de déplacement du personnage

		//Nombre d'animations et frames par animation qu'on a dans notre spriteSheet.
		//Oui c'est hardcodé; on ne peut pas faire autrement
		//Si vous avez une solution venez me l'exposer
		const int NBR_MIVEAUX = 8;  //Total de lignes dans la spiteSheet
		const int NBR_ANIMS_IMMOBILE = 4;  //Nombre de frames d'animation pour le idle dans la spriteSheet.
		const int NBR_ANIMS_MOUVEMENT = 8;  //Nombre de frames d'animation pour le mouvement dans la spriteSheet.
		const int NBR_ANIMS = NBR_ANIMS_IMMOBILE + NBR_ANIMS_MOUVEMENT;  //Nombre de frames d'animation au total dans la spriteSheet.

		const float GAMEPAD_RATIO = 100.0f;   //Pour ramener le gamepad à un ratio -1 à 1, ce qui est de loin le plus pratique
		const float CLAVIER_DROITE = 1.0f;
		const float CLAVIER_DIAGONALE = CLAVIER_DROITE * cos(M_PI_4);  //diagonale qui détermine une pure diagonale de pente 1

		static Texture texture;

		IntRect** intRectsImmobile; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de "idle"  
		IntRect** intRectsMouvement; //Tableau dynamique à deux dimensions pour des rectangles de découpage, pour les animations de mouvement 
		//ce sera un tableau de taille déterminée plus tard car on ne connait pas encore le nombre de frames dans l'animation

		RenderWindow* renderWindow;	//Pointeur sur la fenêtre.  pratique pour connaitre sa taille entre autre

		int cadran;   //Niveau d'animation suivant un cadran. 0 est la direction gauche et on tourne suivant les aiguilles d'une montre
		              //Pourquoi ça? Ouvez la spriteSheet pour comprendre
        float frameCourante;

        float animRate;
        bool isIdle;
        bool isRightFrameIdle;

		Vector2f interfaceDeplacement; //Vecteur de déplacement du personnage
	};
}

