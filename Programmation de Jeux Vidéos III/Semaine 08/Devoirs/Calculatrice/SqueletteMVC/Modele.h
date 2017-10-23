#pragma once
#include <string>

using std::string;

namespace MVC
{
	class Modele
	{
	public:
		Modele();
		string salutations(const string& salutationRecue, int& pointsPolitesse);
        double calculer(double& num1, double& num2, char& operateur);
	private:
		string politesses[3];

	};
}
