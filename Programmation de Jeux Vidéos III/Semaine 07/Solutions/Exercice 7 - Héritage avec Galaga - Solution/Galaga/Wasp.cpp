#include "Wasp.h"

using namespace galaga;

Wasp::Wasp(const float posX, const float posY, const float vitesse, const int niveau, const int nbrNiveaux, const int nbrAnims, RenderWindow  * const renderWindow)
	: Galaga(posX, posY, vitesse, niveau, nbrNiveaux, nbrAnims, renderWindow), vague(0), direction(vitesse)
{

}

Wasp::~Wasp()
{
	// Le destructeur de Butterfly sera automatiquement appel�e
}

void Wasp::deplacement()
{
	//D�placement en X
	move(direction, 0);
	vague += direction;

	if (abs(vague) > 100)
	{
		direction *= -1;
	}

	//D�placement en Y
	Galaga::deplacement();
}

