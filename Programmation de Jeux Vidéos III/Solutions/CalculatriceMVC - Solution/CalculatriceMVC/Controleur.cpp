#include "Controleur.h"
#include <exception>

using namespace MVC;

Controleur *Controleur::instance = nullptr;

Controleur::Controleur()
{

}

Controleur* Controleur::getInstance()
{
	if (!instance)
		instance = new Controleur();
	return instance;
}

void Controleur::release()
{
	delete instance;
	instance = nullptr;
}

bool Controleur::requeteCalcul(const string& nombre1, const string& nombre2, const string& operateur, double& resultat, string& msg)
{
	double d1, d2;

	try
	{
		d1 = std::stod(nombre1);
	}
	catch (std::exception e)
	{
		msg = "Op�ration �chou�e car nombre1 invalide";
		return false;
	}

	try
	{
		d2 = std::stod(nombre2);
	}
	catch (std::exception e)
	{
		msg = "Op�ration �chou�e car nombre2 invalide";
		return false;
	}

	if (operateur == "+" || operateur == "-" || operateur == "*" || operateur == "/")
	{
		resultat = modele.calcul(d1, d2, operateur[0]);
		msg = "Op�ration r�ussie";
		return true;
	}
	else
	{
		msg = "Op�ration �chou�e car op�rateur invalide";
		return false;
	}
}