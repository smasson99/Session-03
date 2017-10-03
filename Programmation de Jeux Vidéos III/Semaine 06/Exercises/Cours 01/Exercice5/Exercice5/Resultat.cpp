#include "Resultat.h"

/**
* Permet de créer un nouveau score pour le pointage et le joueur spécifiés.
* Un fois créé, il n'est plus possible de modifier le joueur et le score, mais le rang peut toujours l'être.
* @param	score	    les points obtenus
* @param	rang        le rang du joueur
* @param	joueur      pointeur sur un joueur existant
*/
Resultat::Resultat(const unsigned int score, unsigned int rang, Joueur& joueur) : score(score), rang(rang), leJoueur(joueur)
{
	//Initialiseurs, plus rapide, demande moins de mémoire et est plus sécure
	//Quand on entre dans le bloc du constructeur d'un certaine manière l'objet existe déjà en mémoire et est modifié
	//Pas avec un initialiseur.
	//Seul endroit où on peut initialiser des membres constantes ou des membres références, qui en C++ n'existe pas de manière null

	//Rang doit être de 1 au minimum.  On peut le modifier, donc n'est pas const.
	if (rang == 0)
	{
		rang = 1;
	}
}

/**
* Libère les éléments dynamiques à la fin de la vie de l'instance
*/
Resultat::~Resultat()
{

}

/**
* Renvoie les points du score
* @return	les points obtenus
*/
unsigned int Resultat::getScore()
{
	return this->score;
}

/**
* Renvoie le rang du joueur
* @return	le rang du joueur
*/
unsigned int Resultat::getRang()
{
	return this->rang;
}

/**
* Ajuste le rang du résultat.
* @param	le nouveau rang
*/
void Resultat::setRang(unsigned int nouveauRang)
{
	this->rang = nouveauRang;
}

/**
* Renvoie le nom du joueur ayant obtenu le score
* @return	le nom du joueur
* @see	Joueur#GetNom()
*/
string Resultat::getNomJoueur()
{
	return leJoueur.getNom();
}

/**
* Renvoie l'adresse courriel du joueur ayant obtenu le score
* @return	l'adresse courriel du joueur
* @see  Joueur#GetCourriel()
*/
string Resultat::getCourrielJoueur()
{
	return this->leJoueur.getCourriel();
}

/**
* Renvoie une représentation textuelle d'un score
* @return  une chaîne de caractère décrivant les caractéristiques d'un score
* @see  Player#ToString()
*/
string Resultat::toString()
{
	std::stringstream ss;
	ss << "RANG " << this->rang << ": " << this->leJoueur.toString() << ", SCORE: " << this->score;
	return ss.str();
}