#include "Modele.h"

using namespace MVC;

Modele::Modele()
{
	politesses[0] = "Salut!";
	politesses[1] = "Allo!";
	politesses[2] = "Bonjour!";
}

string Modele::salutations(const string& salutationRecue, int& pointsPolitesse)
{
	for (int i = 0; i < 3; i++)
	{
		if (salutationRecue == politesses[i])
		{			
			pointsPolitesse = rand() % 10 + 1;
			return "Salutations! Vous �tes quelqu'un de tr�s poli!";
		}
	}

	pointsPolitesse = -1;
	return "ceci n'est pas tr�s convenable!";
}



