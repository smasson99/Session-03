#include "Controleur.h"

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

string Controleur::requetePolitesse(const string& salutationRecue, int& pointsPolitesse)
{
	if (salutationRecue.length() < 5 || salutationRecue.length() > 8)
	{
		pointsPolitesse = -1;
		return "Message de salutation entre 5 et 8 caractères; vous savez pas lire?";
	}

	if (salutationRecue[salutationRecue.length()-1] != '!')
	{
		pointsPolitesse = -1;
		return "Votre salutation est plutôt molle; pas vraiment sincère";
	}

	return modele.salutations(salutationRecue, pointsPolitesse);

	
}