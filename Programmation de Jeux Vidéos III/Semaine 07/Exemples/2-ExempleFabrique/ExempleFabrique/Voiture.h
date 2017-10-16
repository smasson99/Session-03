#pragma once
#include <string>


namespace Fabrique
{
	class Voiture
	{
	public:
		virtual std::string getTypeVoiture() = 0;
	};
}