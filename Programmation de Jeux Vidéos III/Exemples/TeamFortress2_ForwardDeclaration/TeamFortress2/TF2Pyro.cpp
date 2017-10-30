#include "TF2Pyro.h"

using namespace TF2;

TF2Pyro::TF2Pyro()
{
	health = 175;
	typePerso = "pyro";	
}
	
string TF2Pyro::attaqueDistance() const
{
	return "Mff-mff-mff (Je brûle les gens!)";
}
	
string TF2Pyro::attaqueProche() const
{
	return "Mff-mff-mff (Je leur sacre une hache dans la gueule!)";
}	