#include "TF2Perso.h"

using namespace TF2;

TF2Perso::TF2Perso()
{

}
	
string TF2Perso::getTypePerso() const
{
	return typePerso;
}

void TF2Perso::setTypePerso(const string typePerso) 
{
	this->typePerso = typePerso;
}

int TF2Perso::getHealth()  const
{
	return health;
}

void TF2Perso::setHealth(const int health) 
{
	this->health = health;
}
	
string TF2Perso::toString() const
{
	return "Salut! je suis un " + typePerso;
}	
	
string TF2Perso::attaqueDistance() const
{
	return "Attaque générique";
}
	
string TF2Perso::attaqueProche() const
{
	return "Attaque raprochée générique";	
}	