#pragma once
#include "UsineDeVoiture.h"
#include "SportCar.h"


namespace Fabrique
{
	class UsineDeSportCar : public UsineDeVoiture
	{
	public:
		Voiture* fabriquerVoiture()
		{
			return new SportCar();
		}
	};
}