#pragma once

#include "Player.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class Game
{
public:
	Game();
	int run();
	int testTest();

private:
	const int LARGEUR_ECRAN = 1280;
	const int HAUTEUR_ECRAN = 720;

	const int LARGEUR_MONDE = 3384;
	const int HAUTEUR_MONDE = 1656;

	const int CENTRE_MONDE_X = LARGEUR_MONDE / 2;
	const int CENTRE_MONDE_Y = HAUTEUR_MONDE / 2;

	//Puisque la vue utilise des positions centrales, les limites d'affichage
	//sont les positions centrales des cadres limites.
	const int LIMITE_VUE_MIN_X = LARGEUR_ECRAN / 2;
	const int LIMITE_VUE_MIN_Y = HAUTEUR_ECRAN / 2;
	const int LIMITE_VUE_MAX_X = LARGEUR_MONDE - LIMITE_VUE_MIN_X;
	const int LIMITE_VUE_MAX_Y = HAUTEUR_MONDE - LIMITE_VUE_MIN_Y;


	/* Les textures devraient devenir des propri�t�s statiques de leur classes respectives*/
	/* Pour le moment vous pouvez m�me les mettre publique si vous le souhaitez*/
	Texture terrainT;
	Texture joueurT;
	Texture zombieT[3];
	
	
	/* � partir d'ici, certains attributs sont des placeholders temporaires, et ce que vous voulez garder devrait*/
	/* se retrouver de plus en plus � l'int�rieur de classes. Ne faites pas tout d'un coup, allez-y lentement et */
	/* assurez-vous que tout fonctionne, une �tape � la fois*/
	Sprite terrain;
	Sprite joueur;
    Player player;
	Sprite zombie[3];

    /*Voici le vecteur de projectiles du jeu*/
    std::vector<Projectile> projectiles;

	Font police;
	Text texte;
	Music musique;

    //Bool�en indicateurs des inputs
	bool gauche = false;
	bool droite = false;
	bool haut = false;
	bool bas = false;

    bool click = false;
    bool isFirst = true;

	/*Fin du transfert suppos� vers les classes*/

	bool init();
	void getInputs();
	void update();
	void draw();

	void ajusterDepassementLimitesVue();

    Mouse mouse;
	RenderWindow mainWin;
	View view;
	Event event;
};