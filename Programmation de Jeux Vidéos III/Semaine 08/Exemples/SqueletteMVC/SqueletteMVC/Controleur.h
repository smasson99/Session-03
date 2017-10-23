#pragma once
#include <string>
#include "Modele.h"

using std::string;

namespace MVC
{
	class Controleur
	{
	public:
		static Controleur *getInstance();
		static void release();

		//Pour le contr�leur, on utilise souvent requete (request)
		//et le nom de la m�thode qu'on veut utiliser du c�t� du mod�le.
		string requetePolitesse(const string& salutationRecue, int& pointsPolitesse);

	private:
		Controleur();
		static Controleur *instance;

		Controleur(const Controleur&);
		void operator=(const Controleur&);

		//Le contr�leur peut instancier les �l�ments de la couche mod�le, puisque c'est le seul qui est sens� y avoir acc�s.
		//S'il ne les instancie pas, alors il aura des pointeurs vers les classes
		Modele modele;
	};
}

