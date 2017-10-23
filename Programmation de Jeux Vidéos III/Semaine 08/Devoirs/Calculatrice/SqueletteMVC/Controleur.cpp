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

//string Controleur::requetePolitesse(const string& salutationRecue, int& pointsPolitesse)
//{
//	if (salutationRecue.length() < 5 || salutationRecue.length() > 8)
//	{
//		pointsPolitesse = -1;
//		return "Message de salutation entre 5 et 8 caractères; vous savez pas lire?";
//	}
//
//	if (salutationRecue[salutationRecue.length()-1] != '!')
//	{
//		pointsPolitesse = -1;
//		return "Votre salutation est plutôt molle; pas vraiment sincère";
//	}
//
//	return modele.salutations(salutationRecue, pointsPolitesse);
//
//	
//}

//Calculatrice
string MVC::Controleur::requeteCalcul(string& num1, string& num2, char& operateur, string& message)
{
    string messageEDebut = message;
    double cNum1 = 0.1f;
    double cNum2 = 0.1f;
    bool ok = true;
    //Validation num1
    try
    {
        cNum1 = stod(num1);
    }
    catch (const std::invalid_argument&)
    {
        if (messageEDebut == message)
            message = "";
        message += "Le premier nombre est invalide. ";
        ok = false;
    }
    //Validation num2
    try
    {
        cNum2 = stod(num2);
    }
    catch (const std::invalid_argument&)
    {
        if (messageEDebut == message)
            message = "";
        message += "Le deuxième nombre est invalide. ";
        ok = false;
    }
    //Validation opérateur
    bool operatorOk = false;
    switch (operateur)
    {
    case '+':
        operatorOk = true;
        break;
    case '-':
        operatorOk = true;
        break;
    case '*':
        operatorOk = true;
        break;
    case '/':
        operatorOk = true;
        break;
    }
    if (!operatorOk)
    {
        if (messageEDebut == message)
            message = "";
        message += "L'opérateur est invalide. ";
    }
    //Gérer le cas de la division par zéro
    if (cNum2 == 0)
    {
        if (messageEDebut == message)
            message = "";
        message += "Division par zéro impossible.";
        ok = false;
    }
    //Valider et calculer
    if (ok && operatorOk)
    {
        return std::to_string(modele.calculer(cNum1, cNum2, operateur));
    }
    return "Erreur";
}