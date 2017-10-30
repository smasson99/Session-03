#include "TF2Scout.h"

using namespace TF2;

TF2Scout::TF2Scout()
{
	health = 125;
	typePerso = "scout";
}
	
string TF2Scout::attaqueDistance() const
{
		return "Court vite, saute, tire, et back en couvert";
}
	
string TF2Scout::attaqueProche() const
{
		return "Coup de circuit dans ta gueule - BOINK!";		
}	