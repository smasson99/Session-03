#pragma once
#include "UsineDeVoiture.h"
#include "Berline.h"

namespace Fabrique
{
	class UsineDeBerline : public UsineDeVoiture
	{
	public:
		Voiture* fabriquerVoiture()
		{
			return new Berline();
		}
	};
}