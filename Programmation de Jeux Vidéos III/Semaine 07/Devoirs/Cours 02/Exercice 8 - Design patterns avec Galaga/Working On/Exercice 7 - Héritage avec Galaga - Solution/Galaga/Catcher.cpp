#include "Catcher.h"

using namespace galaga;

Catcher::Catcher(const float posX, const float posY, const float vitesse, const int niveau, const int nbrNiveaux, const int nbrAnims, RenderWindow  * const renderWindow)
	: Butterfly(posX, posY, vitesse, niveau, nbrNiveaux, nbrAnims, renderWindow), angleOrbite(0)
{
	//Au d�but la position en backup est la m�me que la position de d�part
	savePosition.x = posX;
	savePosition.y = posY;
}

Catcher::~Catcher()
{
	// Le destructeur de Butterfly sera automatiquement appel�e
}

void Catcher::deplacement()
{
	//On ram�ne notre galaga au centre pour les calculs
	setPosition(savePosition);

	//On se d�place vers le bas (et on g�re de suite les rebords d'�cran)
	move(0, vitesse);
	setPosition(autreCote(getPosition().x, renderWindow->getSize().x, texture.getSize().x / 2), autreCote(getPosition().y, renderWindow->getSize().y, texture.getSize().y / 2));

	//On sauvegarde la position centrale obtenu
	savePosition = getPosition();

	//On ajoute de l'angle
	angleOrbite += VITESSE_ORBITE;

	//On re-d�place notre galaga "en orbite"
	positionOrbite.x = RAYON_ORBITE * cos(angleOrbite);
	positionOrbite.y = RAYON_ORBITE * sin(angleOrbite);
	move(positionOrbite);

	//Et on ajuste � nouveau suivant les rebords
	setPosition(autreCote(getPosition().x, renderWindow->getSize().x, texture.getSize().x / 2), autreCote(getPosition().y, renderWindow->getSize().y, texture.getSize().y / 2));


	if (++animateur % 10 == 0)
	{
		setTextureRect(intRects[(animateur / 10) % 2]);
	}
}
