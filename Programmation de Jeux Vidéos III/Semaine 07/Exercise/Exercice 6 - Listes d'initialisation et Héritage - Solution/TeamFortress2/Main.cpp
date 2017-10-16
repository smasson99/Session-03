#include <iostream>
#include <typeinfo>
#include "TF2Perso.h"
#include "TF2Pyro.h"
#include "TF2Scout.h"
#include "TF2Sniper.h"


using namespace TF2;
using std::cout;
using std::cin;

int main()
{
	setlocale(LC_ALL, "");

	//Concept du polymorphisme: un pointeur de la super-classe peut pointer sur unw sous-classe
	TF2Perso* teamRed[3] = { new TF2Pyro(), new TF2Scout(), new TF2Sniper() };

	//On identifie les personnages et on utilise leurs attaques
	for (int i = 0; i < 3; i++)
	{
		cout << teamRed[i]->toString() <<"\n";
		cout << teamRed[i]->attaqueDistance() <<"\n";
		cout << teamRed[i]->attaqueProche() <<"\n";

		//#2 Festival du copier-coller
		if(typeid(*teamRed[i]) == typeid(TF2Pyro))
		{
			//Si c'est un sniper, on  peut caster le pointeur de personnage en pointeur de sniper
			TF2Pyro *s = (TF2Pyro*)teamRed[i];
			cout << s->BURNNNNNN() << "\n\n";
		}

		//#2 Festival du copier-coller
		if (typeid(*teamRed[i]) == typeid(TF2Scout))
		{
			//Si c'est un sniper, on  peut caster le pointeur de personnage en pointeur de sniper
			TF2Scout *s = (TF2Scout*)teamRed[i];
			cout << s->prendreLePoint() << "\n\n";
		}

		//typeid identifie le type de l'objet
		if (typeid(*teamRed[i]) == typeid(TF2Sniper))
		{
			//Si c'est un sniper, on  peut caster le pointeur de personnage en pointeur de sniper
			TF2Sniper *s = (TF2Sniper*)teamRed[i];
			cout << s->headshot() << "\n\n";
		}
	}

	//#3: Méthodes de la classe de base
	cout << teamRed[0]->TF2Perso::attaqueDistance() << "\n";
	cout << teamRed[0]->TF2Perso::attaqueProche() << "\n\n";

    //Concept du polymorphisme: une référence de la super-classe peut référer sur une sous-classe
	TF2Pyro bluePyro;
	TF2Perso& teamBlu1 = bluePyro;

	//On identifie le personnage et on utilise ses attaques
	cout << teamBlu1.toString() <<"\n";
	cout << teamBlu1.attaqueDistance() <<"\n";
	cout << teamBlu1.attaqueProche() <<"\n\n";

	//On évite les leaks, juste pour être certain
	for (int i = 0; i < 3; i++)
	{
		delete teamRed[i];
	}

	system("pause");
	return 0;
}
