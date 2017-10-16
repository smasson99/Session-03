#pragma once
#include "Voiture.h"

namespace Fabrique
{
	class UsineDeVoiture
	{
	public:
		virtual Voiture* fabriquerVoiture() = 0;
	};
}
