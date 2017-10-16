#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace galaga
{
	class Galaga : public Sprite
	{
	public:
		//Constructeur avec tous les attributs plus haut.  Utiliser un tableau de char pour le path évite d'inclure string et un string a un constructeur avec un tableau de char
		Galaga(const float posX, const float posY, const float vitesse, 
            const int niveau, const int nbrNiveaux, const int nbrAnims, 
            RenderWindow* const renderWindow);
		~Galaga();

		static bool chargerTexture(const char texturePath[]);

		//Méthode de "finalisation du constructeur"
		void ajustementsVisuels();


		virtual void deplacement() = 0;


	protected:	
		static Texture texture;

		/// <summary>
		/// Pointeur sur la fenêtre.  pratique pour connaitre sa taille entre autre
		/// </summary>
		RenderWindow* renderWindow;
		
		/// <summary>
		/// Vitesse de déplacement du galaga vers le bas
		/// </summary>
		float vitesse;
				
		/// <summary>
		/// Pour l'animation des frames du galaga
		/// </summary>
		int animateur;
		
		/// <summary>
		/// Tableau de rectangles de découpage sur la spriteSheet. 
		/// ce sera un tableaau de taille déterminée plus tard car on ne connait pas encore le nombre de frames dans l'animation.
		/// </summary>
		IntRect* intRects;

		//Les variables suivantes sont pour le découpage de la spriteSheet
				
		/// <summary>
		/// ligne à partir de 0 de notre sprite dans la spiteSheet
		/// </summary>
		const int NIVEAU;
				
		/// <summary>
		/// Total de lignes dans la spiteSheet
		/// </summary>
		const int NBR_MIVEAUX;
		
		/// <summary>
		/// Nombre de frame d'animation dans la spiteSheet.
		/// </summary>
		const int NBR_ANIMS;

		/// <summary>
		/// Modifie un des axe du vaisseau s'il dépasse la limite de l'écran de plus
		/// de la moitié de sa taille (donc au moment où il disparait de l'écran.
		/// </summary>
		/// <param name="position">La position de l'axe.</param>
		/// <param name="tailleEcran">La taille de l'écran pour cet axe.</param>
		/// <param name="demiTailleVaisseau">La taille de la moitié du vaisseau, du centre à son extrémité, toujours dans le meme axe.</param>
		/// <returns>Position finale, qui sera la même que position de l'axe s'il n'y a pas téléportation.</returns>
		float autreCote(float positionDansAxe, const int tailleEcran, const int demiTailleVaisseau);
	};
}

