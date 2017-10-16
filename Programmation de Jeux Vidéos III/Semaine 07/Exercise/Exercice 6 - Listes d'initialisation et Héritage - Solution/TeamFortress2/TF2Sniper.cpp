#include "TF2Sniper.h"

using namespace TF2;

//#1: Liste d'initialisation
TF2Sniper::TF2Sniper() :TF2Perso(125, "sniper")
{

}
	
string TF2Sniper::attaqueDistance() const
{
		return "A good kill need only one bullet mate!";
}
	
string TF2Sniper::attaqueProche() const
{
		return "I'm a black belt in jarate, mate";		
}

string TF2Sniper::headshot() const
{
		return "Boom! Headshot!";	
}	