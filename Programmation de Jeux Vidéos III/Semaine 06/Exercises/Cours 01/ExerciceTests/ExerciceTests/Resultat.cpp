#include "Resultat.h"

/**
* Permet de cr�er un nouveau score pour le pointage et le joueur sp�cifi�s.
* Un fois cr��, il n'est plus possible de modifier le joueur et le score, mais le rang peut toujours l'�tre.
* @param	score	    les points obtenus
* @param	rang        le rang du joueur
* @param	joueur      pointeur sur un joueur existant
*/
Resultat::Resultat(const unsigned int score, unsigned int rang, Joueur& joueur) : score(score), rang(rang), leJoueur(joueur)
{
	//Initialiseurs, plus rapide, demande moins de m�moire et est plus s�cure
	//Quand on entre dans le bloc du constructeur d'un certaine mani�re l'objet existe d�j� en m�moire et est modifi�
	//Pas avec un initialiseur.
	//Seul endroit o� on peut initialiser des membres constantes ou des membres r�f�rences, qui en C++ n'existe pas de mani�re null

	//Rang doit �tre de 1 au minimum.  On peut le modifier, donc n'est pas const.
	if (rang == 0)
	{
		rang = 1;
	}
}

/**
* Lib�re les �l�ments dynamiques � la fin de la vie de l'instance
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
* Ajuste le rang du r�sultat.
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
* Renvoie une repr�sentation textuelle d'un score
* @return  une cha�ne de caract�re d�crivant les caract�ristiques d'un score
* @see  Player#ToString()
*/
string Resultat::toString()
{
	std::stringstream ss;
	ss << "RANG " << this->rang << ": " << this->leJoueur.toString() << ", SCORE: " << this->score;
	return ss.str();
}