#include "Wasp.h"

using namespace galaga;

Wasp::Wasp(const float posX, const float posY, const float vitesse, const int niveau, RenderWindow  * const renderWindow)
	: Galaga(posX, posY, vitesse, niveau, renderWindow), vague(0), direction(vitesse)
{

}

Wasp::~Wasp()
{
	// Le destructeur de Butterfly sera automatiquement appelée
}

void Wasp::deplacement()
{
	//Déplacement en X
	position.x += direction;
	vague += direction;

	if (abs(vague) > 100)
	{
		direction *= -1;
	}

	//Déplacement en Y
	Galaga::deplacement();
}

