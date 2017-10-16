#pragma once
#include <string>
#include "Voiture.h"

namespace Fabrique
{
	class Berline : public Voiture
	{
	public:
		std::string getTypeVoiture()
		{
			return "Berline";
		}
	};
}