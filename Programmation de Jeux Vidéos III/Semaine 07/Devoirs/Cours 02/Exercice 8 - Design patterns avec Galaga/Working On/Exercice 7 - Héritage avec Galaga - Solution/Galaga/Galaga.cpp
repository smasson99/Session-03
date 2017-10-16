#include "Galaga.h"

using namespace galaga;

Texture Galaga::texture; //Initialisation de notre texture (appel du constructeur par dfaut)

Galaga::Galaga(const float posX, const float posY, const float vitesse, const int niveau, const int nbrNiveaux, const int nbrAnims, RenderWindow  * const renderWindow)
	: vitesse(vitesse), renderWindow(renderWindow), NIVEAU(niveau), NBR_MIVEAUX(nbrNiveaux), NBR_ANIMS(nbrAnims), animateur(0)
{
	setPosition(posX, posY);
	setRotation(180);	//Le galaga plonge vers le bas.
}

Galaga::~Galaga()
{
	//Effacement correct de nos rectangles.
	delete[] intRects;
}

bool Galaga::chargerTexture(const char texturePath[])
{
	//Chargement du fichier de texture
	if (!texture.loadFromFile(texturePath))
	{
		return false;
	}

	texture.setSmooth(true);
	return true;
}

void Galaga::ajustementsVisuels()
{
	setTexture(texture);   //Placement de la texture dans le sprite
	intRects = new IntRect[NBR_ANIMS];  //Tableau de frames dépendant du nombre d'animations

										//On se taille des rectangles d'animation à partir des caractérisitques de la spriteSheet
										//Et de la ligne d'animation
	for (int i = 0; i < NBR_ANIMS; i++)
	{
		intRects[i].left = (texture.getSize().x / NBR_ANIMS) * i;
		intRects[i].top = (texture.getSize().y / NBR_MIVEAUX) * NIVEAU;
		intRects[i].width = (texture.getSize().x / NBR_ANIMS);
		intRects[i].height = (texture.getSize().y / NBR_MIVEAUX);
	}

	//Le rectangle d'animation initial de notre texture est le premier rectangle.
	setTextureRect(intRects[0]);

	//L'origine est toujours le milieu de notre rectangle de texture.
	//Comme vu ci-haut, c'est la moitié du rectangle d'animation, pas de la texture entière
	//La première ligne de code peut faire, mais la seconde est mieux.
	//setOrigin((texture.getSize().x / NBR_ANIMS) / 2, (texture.getSize().y / NBR_MIVEAUX) / 2);
	setOrigin(intRects[0].height / 2, intRects[0].width / 2);
}

void Galaga::deplacement()
{
	//Déplacement vers le bas
	move(0, vitesse);

	//Test pour la traverse des autres côtés de l'écran
	setPosition(autreCote(getPosition().x, renderWindow->getSize().x, texture.getSize().x / 2), autreCote(getPosition().y, renderWindow->getSize().y, texture.getSize().y / 2));

	//Changement de frame aux 10 frames
	setTextureRect(intRects[(animateur++ / 10) % 2]);
}


float Galaga::autreCote(float positionDansAxe, const int tailleEcran, const int demiTailleVaisseau)
{
	if (positionDansAxe > tailleEcran + demiTailleVaisseau)
	{
		positionDansAxe -= tailleEcran + demiTailleVaisseau * 2;
	}
	else if (positionDansAxe < -demiTailleVaisseau)
	{
		positionDansAxe += tailleEcran + demiTailleVaisseau * 2;
	}
	return positionDansAxe;
}

