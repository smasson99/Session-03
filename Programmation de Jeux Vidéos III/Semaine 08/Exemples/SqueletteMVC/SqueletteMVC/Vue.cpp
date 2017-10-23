#include "Vue.h"
#include <iostream>
#include "Controleur.h"

using namespace std;
using namespace MVC;

Vue::Vue()
{
}

void Vue::executer()
{
	string message;
	int tauxSatisfactionTotal = 0;

	while (true)
	{
		int tauxSatisfaction = 0;
		cout << "Veullez entrez une salutation entre 5 et 8 charactères," << endl <<"dont le dernier est un point d'exclamation!" << endl;
		cin >> message;
		
		cout << Controleur::getInstance()->requetePolitesse(message, tauxSatisfaction) <<endl;
		tauxSatisfactionTotal += tauxSatisfaction;

		cout << "Le taux de satisfaction total à ce stade-ci est de " << tauxSatisfactionTotal << endl << endl << "Souhaitez-vous continuer? (o/n)";

		string reponse;
		cin >> reponse;

		if (reponse != "o" && reponse != "O") break;
	}
}
