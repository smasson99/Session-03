#pragma once
#include <string>
#include "Voiture.h"

namespace Fabrique
{
	class PickUp : public Voiture
	{
	public:
		std::string getTypeVoiture()
		{
			return "Pick Up";
		}
	};
}