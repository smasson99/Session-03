#include "TF2Pyro.h"

using namespace TF2;

//#1: Liste d'initialisation
TF2Pyro::TF2Pyro() :TF2Perso(175, "pyro")
{

}
	
string TF2Pyro::attaqueDistance() const
{
	return "Mff-mff-mff (Je brûle les gens!)";
}
	
string TF2Pyro::attaqueProche() const
{
	return "Mff-mff-mff (Je leur sacre une hache dans la gueule!)";
}	

//#2 Festival du copier-coller
string TF2Pyro::BURNNNNNN() const
{
	return "Mff-mff-mff (FOUTONS L'FEU! FOUTONS L'FEU!)";
}