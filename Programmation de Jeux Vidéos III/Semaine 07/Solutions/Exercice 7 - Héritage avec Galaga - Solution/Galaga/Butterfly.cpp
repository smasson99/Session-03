#include "Butterfly.h"

using namespace galaga;

Butterfly::Butterfly(const float posX, const float posY, const float vitesse, const int niveau, const int nbrNiveaux, const int nbrAnims, RenderWindow  * const renderWindow)
	: Galaga(posX, posY, vitesse, niveau, nbrNiveaux, nbrAnims, renderWindow)
{

}

Butterfly::~Butterfly()
{
	// Le destructeur de Butterfly sera automatiquement appelée
}

void Butterfly::deplacement()
{
	//On ne fait rien de plus, juste concrétiser.
	Galaga::deplacement();
}