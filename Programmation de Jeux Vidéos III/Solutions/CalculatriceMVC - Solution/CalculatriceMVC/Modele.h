#pragma once
#include <string>

using std::string;

namespace MVC
{
	class Modele
	{
	public:
		Modele();
		double calcul(double nombre1, double nombre2, char operateur);
	};
}
