#ifndef _DEBUG
#define NDEBUG 
#endif
#include <iostream>
#include <typeinfo>
#include <cassert>

#include "TF2Pyro.h"
#include "TF2Scout.h"
#include "TF2Sniper.h"
#include "TF2Medic.h"
#include "TF2Heavy.h"


using namespace TF2;
using std::cout;
using std::cin;

int main()
{
	setlocale(LC_ALL, "");

	//assert(false && "Un beau assert gratis de même! (Il vous coûte zéro; pas une cenne!!!)");

	//Concept du polymorphisme: un pointeur de la super-classe peut pointer sur unw sous-classe
	TF2Perso* teamRed[5] = { new TF2Pyro(), new TF2Scout(), new TF2Sniper(), new TF2Medic(), new TF2Heavy() };

	//On identifie les personnages et on utilise leurs attaques
	for (int i = 0; i < 5; i++)
	{
		cout << teamRed[i]->toString() <<"\n";
		cout << teamRed[i]->attaqueDistance() <<"\n";
		cout << teamRed[i]->attaqueProche() <<"\n\n";

		//typeid identifie le tyoe de l'objet
		if(typeid(*teamRed[i]) == typeid(TF2Sniper))
		{
			//Si c'est un sniper, on  peut caster le pointeur de personnage en pointeur de sniper
			TF2Sniper *s = (TF2Sniper*)teamRed[i];
			cout << s->headshot() << "\n\n";
		}

		//typeid identifie le tyoe de l'objet
		if (typeid(*teamRed[i]) == typeid(TF2Medic))
		{			
			TF2Medic *m = (TF2Medic*)teamRed[i];

			for (int j = 0; j < 5; j++)
			{
				if (typeid(*teamRed[j]) == typeid(TF2Heavy))
				{
					cout << "Oh, lé membré de l'éguipe en indize " << j << " est un heavy; jé vé lé zoigner!\n";

					TF2Heavy *h = (TF2Heavy*)teamRed[j];
					cout << m->soignerHeavy(h) << "\n\n";
					cout << h->bizou(m);
					cout << "\n\n";
				}
			}
		}
	}

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
