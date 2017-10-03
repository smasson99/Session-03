#include "Galaga.h"

using namespace galaga;

Galaga::Galaga(const float posX, const float posY, const float vitesse, const int niveau, 
    const int nbrNiveaux, const int nbrAnims, RenderWindow  * const renderWindow):vitesse(vitesse), 
    animateur(0), renderWindow(renderWindow), niveau(niveau), nbrNiveaux(nbrNiveaux), nbrAnims(nbrAnims)
{

	//Tableau de frames dépendant du nombre d'animations
	intRects = new IntRect[nbrAnims];

	//On se découpe des rectangles d'animation à partir des caractéristiques de la spriteSheet
	//Et de la ligne d'animation
	for (int i = 0; i < nbrAnims; i++)
	{
		intRects[i].left = (texture.getSize().x / nbrAnims) * i;
		intRects[i].top = (texture.getSize().y / nbrNiveaux) * niveau;
		intRects[i].width = (texture.getSize().x / nbrAnims);
		intRects[i].height = (texture.getSize().y / nbrNiveaux);
	}

	//Le rectangle de notre texture est le premier rectangle.
	setTextureRect(intRects[0]);

	//L'origine est toujours le milieu de notre texture.  Mais on la calcule en fonction de la taille d'UNE image, pas de la texture entière
	setOrigin((texture.getSize().x / nbrAnims) / 2, (texture.getSize().y / nbrNiveaux) / 2);

	setPosition(posX, posY);
}

Galaga::~Galaga()
{
	//Effacement correct de nos rectangles.
	delete[] intRects;
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

bool galaga::Galaga::Init(const char texturePath[])
{
    //Chargement du fichier de texture et placement dans le sprite.
    bool hasLoaded = texture.loadFromFile(texturePath);
    texture.setSmooth(true);
    if (hasLoaded)
        setTexture(texture);
    return hasLoaded;
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

