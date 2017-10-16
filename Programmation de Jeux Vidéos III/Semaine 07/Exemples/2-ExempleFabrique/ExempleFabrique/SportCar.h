#pragma once
#include <string>
#include "Voiture.h"

namespace Fabrique
{
	class SportCar : public Voiture
	{
	public:
		std::string getTypeVoiture()
		{
			return "Sport Car";
		}
	};
}