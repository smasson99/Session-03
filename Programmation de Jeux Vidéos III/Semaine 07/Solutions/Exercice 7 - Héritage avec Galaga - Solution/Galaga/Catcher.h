#pragma once
#include "Butterfly.h"

namespace galaga
{
	class Catcher : public Butterfly
	{
	public:
		Catcher(const float posX, const float posY, const float vitesse, const int niveau, const int nbrNiveaux, const int nbrAnims, RenderWindow* const renderWindow);
		~Catcher();

		void deplacement();

	private:
		Vector2f savePosition;  //backup de la position centrale
		Vector2f positionOrbite; //position calculé à partir de l'angle de l'orbite et du raynon
		float angleOrbite;  //Angle du "galaga en orbite" par rapport à sa position
		const float RAYON_ORBITE = 100.0f;
		const float VITESSE_ORBITE = 0.1f;
	};
}