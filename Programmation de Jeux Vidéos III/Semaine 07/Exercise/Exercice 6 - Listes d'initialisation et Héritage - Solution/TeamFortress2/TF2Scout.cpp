#include "TF2Scout.h"

using namespace TF2;

//#1: Liste d'initialisation
TF2Scout::TF2Scout() :TF2Perso(125, "scout")
{

}
	
string TF2Scout::attaqueDistance() const
{
		return "Court vite, saute, tire, et back en couvert";
}
	
string TF2Scout::attaqueProche() const
{
		return "Coup de circuit dans ta gueule - BOINK!";		
}

//#2 Festival du copier-coller
string TF2Scout::prendreLePoint() const
{
	return "Tout le monde peut prendre un point, mais moi je le fais à la manière MAX POWER, c'est à dire PLUS VITE!";
}