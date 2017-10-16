#include "Catcher.h"

using namespace galaga;

Catcher::Catcher(const float posX, const float posY, const float vitesse, const int niveau, const int nbrNiveaux, const int nbrAnims, RenderWindow  * const renderWindow)
	: Butterfly(posX, posY, vitesse, niveau, nbrNiveaux, nbrAnims, renderWindow), angleOrbite(0)
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
	setPosition(savePosition);

	//On se déplace vers le bas (et on gère de suite les rebords d'écran)
	move(0, vitesse);
	setPosition(autreCote(getPosition().x, renderWindow->getSize().x, texture.getSize().x / 2), autreCote(getPosition().y, renderWindow->getSize().y, texture.getSize().y / 2));

	//On sauvegarde la position centrale obtenu
	savePosition = getPosition();

	//On ajoute de l'angle
	angleOrbite += VITESSE_ORBITE;

	//On re-déplace notre galaga "en orbite"
	positionOrbite.x = RAYON_ORBITE * cos(angleOrbite);
	positionOrbite.y = RAYON_ORBITE * sin(angleOrbite);
	move(positionOrbite);

	//Et on ajuste à nouveau suivant les rebords
	setPosition(autreCote(getPosition().x, renderWindow->getSize().x, texture.getSize().x / 2), autreCote(getPosition().y, renderWindow->getSize().y, texture.getSize().y / 2));


	if (++animateur % 10 == 0)
	{
		setTextureRect(intRects[(animateur / 10) % 2]);
	}
}
