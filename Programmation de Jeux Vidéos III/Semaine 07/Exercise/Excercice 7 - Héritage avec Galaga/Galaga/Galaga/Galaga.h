#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace galaga
{
	class Galaga : public Sprite
	{
	public:
		//Constructeur avec tous les attributs plus haut.  Utiliser un tableau de char pour le path �vite d'inclure string et un string a un constructeur avec un tableau de char
		Galaga(const float posX, const float posY, const float vitesse, const int niveau, const int nbrNiveaux, const int nbrAnims, RenderWindow* const renderWindow);
        //Destructeur
		~Galaga();
		void deplacement();
        bool Init(const char texturePath[]);


	private:		
		/// <summary>
		/// Pointeur sur la fen�tre.  pratique pour connaitre sa taille entre autre
		/// </summary>
		RenderWindow* renderWindow;
		
		Texture texture;
		
		/// <summary>
		/// Vitesse de d�placement du galaga vers le bas
		/// </summary>
		float vitesse;
				
		/// <summary>
		/// Pour l'animation des frames du galaga
		/// </summary>
		int animateur;
		
		/// <summary>
		/// Tableau de rectangles de d�coupage sur la spriteSheet. 
		/// ce sera un tableaau de taille d�termin�e plus tard car on ne connait pas encore le nombre de frames dans l'animation.
		/// </summary>
		IntRect* intRects;

		//Les variables suivantes sont pour le d�coupage de la spriteSheet
				
		/// <summary>
		/// ligne � partir de 0 de notre sprite dans la spiteSheet
		/// </summary>
		int niveau;
				
		/// <summary>
		/// Total de lignes dans la spiteSheet
		/// </summary>
		int nbrNiveaux;
		
		/// <summary>
		/// Nombre de frame d'animation dans la spiteSheet.
		/// </summary>
		int nbrAnims;


		/// <summary>
		/// Modifie un des axe du vaisseau s'il d�passe la limite de l'�cran de plus
		/// de la moiti� de sa taille (donc au moment o� il disparait de l'�cran.
		/// </summary>
		/// <param name="position">La position de l'axe.</param>
		/// <param name="tailleEcran">La taille de l'�cran pour cet axe.</param>
		/// <param name="demiTailleVaisseau">La taille de la moiti� du vaisseau, du centre � son extr�mit�, toujours dans le meme axe.</param>
		/// <returns>Position finale, qui sera la m�me que position de l'axe s'il n'y a pas t�l�portation.</returns>
		float autreCote(float positionDansAxe, const int tailleEcran, const int demiTailleVaisseau);
	};
}

