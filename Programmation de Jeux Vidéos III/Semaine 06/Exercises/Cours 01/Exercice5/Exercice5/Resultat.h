#pragma once
#include "Joueur.h"
#include <string>
#include <sstream>

using std::string;

class Resultat
{
public:
	Resultat(const unsigned int score, unsigned int rang, Joueur& joueur);
	~Resultat();

	unsigned int getScore();
	unsigned int getRang();
	void setRang(unsigned int nouveauRang);

	string getNomJoueur();
	string getCourrielJoueur();
	string toString();

private:
	/**
	* Les points obtenus par le joueur
	*/
	unsigned int score;
	/**
	* Les points obtenus par le joueur
	*/
	unsigned int rang;

	/**
	* POinteur sur le joueur associé
	*/
	Joueur& leJoueur;
};
