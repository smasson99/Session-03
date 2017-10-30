#include "Catcher.h"

using namespace galaga;

Catcher::Catcher(const float posX, const float posY, const float vitesse, const int niveau, RenderWindow  * const renderWindow)
	: Galaga(posX, posY, vitesse, niveau, renderWindow), angleOrbite(0)
{
	//Au début la position en backup est la même que la position de départ
	savePosition.x = posX;
	savePosition.y = posY;
}

Catcher::~Catcher()
{
	// Le destructeur de Butterfly sera automatiquement appelée
}

void Catcher::deplacement()
{
	//On ramène notre galaga au centre pour les calculs
	position = savePosition;

	//On se déplace vers le bas (et on gère de suite les rebords d'écran)
	position.y += vitesse;
	
	position.x = autreCote(position.x, renderWindow->getSize().x, texture.getSize().x / 2);
	position.y = autreCote(position.y, renderWindow->getSize().y, texture.getSize().y / 2);

	//On sauvegarde la position centrale obtenu
	savePosition = position;

	//On ajoute de l'angle
	angleOrbite += VITESSE_ORBITE;

	//On re-déplace notre galaga "en orbite"
	position.x += RAYON_ORBITE * cos(angleOrbite);
	position.y += RAYON_ORBITE * sin(angleOrbite);

	//Et on ajuste à nouveau suivant les rebords
	position.x = autreCote(position.x, renderWindow->getSize().x, texture.getSize().x / 2);
	position.y = autreCote(position.y, renderWindow->getSize().y, texture.getSize().y / 2);


	//Changement de frame aux 10 frames
	rectActuel = (animateur++ / 10) % 2;
}
