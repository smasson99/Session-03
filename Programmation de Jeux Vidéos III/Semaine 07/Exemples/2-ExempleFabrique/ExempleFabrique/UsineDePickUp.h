#pragma once
#include "UsineDeVoiture.h"
#include "PickUp.h"


namespace Fabrique
{
	class UsineDePickUp : public UsineDeVoiture
	{
	public:
		Voiture* fabriquerVoiture()
		{
			return new PickUp();
		}
	};
}