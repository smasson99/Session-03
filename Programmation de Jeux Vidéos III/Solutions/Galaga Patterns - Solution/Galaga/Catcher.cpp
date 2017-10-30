#include "Catcher.h"

using namespace galaga;

Catcher::Catcher(const float posX, const float posY, const float vitesse, const int niveau, RenderWindow  * const renderWindow)
	: Galaga(posX, posY, vitesse, niveau, renderWindow), angleOrbite(0)
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
	position = savePosition;

	//On se d�place vers le bas (et on g�re de suite les rebords d'�cran)
	position.y += vitesse;
	
	position.x = autreCote(position.x, renderWindow->getSize().x, texture.getSize().x / 2);
	position.y = autreCote(position.y, renderWindow->getSize().y, texture.getSize().y / 2);

	//On sauvegarde la position centrale obtenu
	savePosition = position;

	//On ajoute de l'angle
	angleOrbite += VITESSE_ORBITE;

	//On re-d�place notre galaga "en orbite"
	position.x += RAYON_ORBITE * cos(angleOrbite);
	position.y += RAYON_ORBITE * sin(angleOrbite);

	//Et on ajuste � nouveau suivant les rebords
	position.x = autreCote(position.x, renderWindow->getSize().x, texture.getSize().x / 2);
	position.y = autreCote(position.y, renderWindow->getSize().y, texture.getSize().y / 2);


	//Changement de frame aux 10 frames
	rectActuel = (animateur++ / 10) % 2;
}
