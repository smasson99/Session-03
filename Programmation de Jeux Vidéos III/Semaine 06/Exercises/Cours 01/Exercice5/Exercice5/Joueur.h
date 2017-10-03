#pragma once
#include <string>

using std::string;

/**
* La classe Joueur décrit les informations sur un joueur.
* Le nom et l'adresse courriel sont obligatoires.
*/
class Joueur
{
public:
	Joueur(const string nom, const string courriel);
	string getNom() const;
	string getCourriel() const;
	bool setCourriel(const string nouveauCourriel);
	string toString() const;

private:
	bool validerAddresseCourriel(const string addresseCourriel) const;

	/**
	*  Le nom du joueur
	*/
	string nom;

	/**
	*  L'adresse courriel du joueur
	*/
	string courriel;


};
