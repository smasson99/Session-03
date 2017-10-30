#include "TF2Sniper.h"

using namespace TF2;

TF2Sniper::TF2Sniper()
{
	health = 125;
	typePerso = "sniper";
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