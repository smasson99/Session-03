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
	string nombre1;
	string nombre2;
	string operateur;

	double reponse;
	string message;

	while (true)
	{
		cout << "Veullez entrer le premier nombre: ";
		cin >> nombre1;

		cout << "Veullez entrer le second nombre: ";
		cin >> nombre2;

		cout << "Veullez entrer l'opérateur: ";
		cin >> operateur;
		
		bool reussite = Controleur::getInstance()->requeteCalcul(nombre1, nombre2, operateur, reponse, message);

		if (reussite)
		{
			cout << endl << endl << message << ": la réponse est: " << reponse << endl << endl;
		}
		else
		{
			cout << endl << endl << message << endl << endl;
		}

		cout <<"Souhaitez-vous refaire un autre calcul? (o/n)";

		string choix;
		cin >> choix;

		if (choix != "o" && choix != "O") break;
	}
}
