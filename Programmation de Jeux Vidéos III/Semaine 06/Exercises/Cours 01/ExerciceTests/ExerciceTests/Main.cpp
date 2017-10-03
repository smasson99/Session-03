#include <vld.h>
#include <iostream>
#include "Joueur.h"
#include "Resultat.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "");

	cout << "\nTESTS DE LA CLASSE Joueur\n\n";

	Joueur eric("EricLeBarbare", "etremblay@hotmail.com");
	cout << "Création du joueur Éric: \n" << eric.toString() << endl;

	Joueur joe("JoeLaTerreur", "joe@gmail.com");
	cout << "Création du joueur Joe: \n" << joe.toString() << endl;

	Joueur invalide("Toto", "toto#@.comm");
	cout << "Création d'un joueur invalide (adresse courriel invalide): \n" << invalide.toString() << endl;

	// Classe Resultat
	cout << "\n\nTESTS DE LA CLASSE Score\n\n";

	Resultat ericResultat1(150000, 1, eric);
	cout << "Création d'un résultat pour Éric: \n" << ericResultat1.toString();

	// Tableaux des joueurs
	cout << "\n\n\nLISTE DES JOUEURS\n\n";

    int joueursLength = 4;
    Joueur* Joueurs[4];
	Joueurs[0] = &eric;
	Joueurs[1] = &joe;
	Joueurs[2] = new Joueur("MayLaFurie", "may@gmail.com");
	Joueurs[3] = new Joueur("GrandSage", "david@yahoo.ca");

	for (Joueur *p : Joueurs)
	{
		cout << p->toString() << endl;
	}

	//Leak, on fait quoi???
    delete[] Joueurs; /*???*/

	system("pause");
}