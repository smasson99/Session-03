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
	/*string message;
	int tauxSatisfactionTotal = 0;

	while (true)
	{
		int tauxSatisfaction = 0;
		cout << "Veullez entrez une salutation entre 5 et 8 charact�res," << endl <<"dont le dernier est un point d'exclamation!" << endl;
		cin >> message;
		
		cout << Controleur::getInstance()->requetePolitesse(message, tauxSatisfaction) <<endl;
		tauxSatisfactionTotal += tauxSatisfaction;

		cout << "Le taux de satisfaction total � ce stade-ci est de " << tauxSatisfactionTotal << endl << endl << "Souhaitez-vous continuer? (o/n)";

		string reponse;
		cin >> reponse;

		if (reponse != "o" && reponse != "O") break;
	}*/

    //Calculatrice
    //Tant que nous d�sirons continuer
    while (true)
    {
        //Message de premier nombre
        cout << "Entrez un premier nombre:" << endl;
        string num1;
        cin >> num1;

        //Message deuxi�me nombre
        cout << "Entrez un deuxi�me nombre:" << endl;
        string num2;
        cin >> num2;

        //Message op�rateur
        cout << "Entrez un op�rateur +, -, * ou /:" << endl;
        string operateur;
        cin >> operateur;

        //Appeler contr�lleur
        string errorMessage = "Calcul effectu� avec succ�s.";
        string res = Controleur::getInstance()->requeteCalcul(num1, num2, operateur[0], errorMessage);
        cout << errorMessage << endl << "R�sultat: " << res << '.' << endl << endl;

        //Demander si veut continuer
        cout << "Souhaitez-vous continuer (O/N)?" << endl;
        string rep;
        cin >> rep;
        cout << endl;
        //Sortir si n�cessaire de la boucle
        if (rep != "o" && rep != "O") break;
    }
}
