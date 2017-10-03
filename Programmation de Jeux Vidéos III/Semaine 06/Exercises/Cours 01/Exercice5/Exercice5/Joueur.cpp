//#include <cctype>
#include <locale>
#include <stdio.h>
#include "Joueur.h"


/**
* Permet de cr�er un nouveau joueur avec le nom et l'adresse courriel sp�cifi�s.
* Il n'est pas possible de modifier le nom d'un joueur apr�s la cr�ation de l'objet correspondant.
* Si l'adresse courriel est invalide, alors elle devient une string vide.
* @param	le nom du joueur
* @param	l'adresse du joueur
* @see		Joueur#ValiderAddresseCourriel()
*/
Joueur::Joueur(string nom, string courriel)
{
	this->nom = nom;

	//Oooooo, Pas safe, mais parfois, on a pas le choix
	if (this->validerAddresseCourriel(courriel))
	{
		this->courriel = courriel;
	}
	else
	{
		this->courriel = "";
	}
}

/**
* Renvoie le nom du joueur
* @return	le nom
*/
string Joueur::getNom() const
{
	return this->nom;
}

/**
* Renvoie l'adresse courriel du joueur
* @return	l'adresse courriel
*/
string Joueur::getCourriel() const
{
	return this->courriel;
}

/**
* Change l'adresse courriel du joueur avec la valeur sp�cifi�e.
* La nouvelle adresse doit �tre une adresse courriel valide.
* @param	la nouvelle adresse courriel
* @return	le r�sultat � savoir si le courriel s'est correctement mis � jour.
* @see		Joueur#ValiderAddresseCourriel()
*/
bool Joueur::setCourriel(string nouveauCourriel)
{
	if (this->validerAddresseCourriel(nouveauCourriel))
	{
		this->courriel = nouveauCourriel;
		return true;
	}
	return false;
}

/**
* Renvoie une repr�sentation textuelle d'un joueur
* @return		une cha�ne de caract�re d�crivant les caract�ristiques du joueur
*/
string Joueur::toString() const
{
	return	("JOUEUR - Nom : " + this->getNom() + ", Courriel : " + this->getCourriel());
}

/**
* V�rifie si l'adresse courriel sp�cifi�e est valide.
* @param	l'adresse courriel � valider
* @return	true, si l'adresse est une adresse courriel valide, false sinon.
*/
bool Joueur::validerAddresseCourriel(const string addresseCourriel) const
{
	/* TODO: ins�rer ici le code de validation d'une adresse courriel */
    string prefix = addresseCourriel.substr(0, addresseCourriel.find("@")-1);
    string sufix = addresseCourriel.substr(addresseCourriel.find("@")+1, addresseCourriel.find(".")-1);
    string nomDomaine = addresseCourriel.substr(addresseCourriel.find(".") + 1, addresseCourriel.length());
	return true;
}

//Note: vous pouvez ajouter des m�thodes priv�es suppl�mentaires
//      que validerAddresseCourriel pourra utiliser
