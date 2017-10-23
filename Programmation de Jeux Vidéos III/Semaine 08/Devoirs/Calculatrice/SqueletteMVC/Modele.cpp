#include "Modele.h"

using namespace MVC;

Modele::Modele()
{
    /*politesses[0] = "Salut!";
    politesses[1] = "Allo!";
    politesses[2] = "Bonjour!";*/

    //Calculatrice
}

//string Modele::salutations(const string& salutationRecue, int& pointsPolitesse)
//{
//	for (int i = 0; i < 3; i++)
//	{
//		if (salutationRecue == politesses[i])
//		{			
//			pointsPolitesse = rand() % 10 + 1;
//			return "Salutations! Vous êtes quelqu'un de très poli!";
//		}
//	}
//
//	pointsPolitesse = -1;
//	return "ceci n'est pas très convenable!";
//}

//Calculatrice
double MVC::Modele::calculer(double& num1, double& num2, char& operateur)
{
    switch (operateur)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    }
}



