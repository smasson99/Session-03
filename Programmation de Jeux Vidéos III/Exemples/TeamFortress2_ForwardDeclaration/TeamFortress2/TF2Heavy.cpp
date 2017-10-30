#include "TF2Heavy.h"
#include "TF2Medic.h"

using namespace TF2;

TF2Heavy::TF2Heavy()
{
	health = 300;
	typePerso = "Heavy";
}

string TF2Heavy::attaqueDistance() const
{
	return "HAHAHAHAHA DAKKA-DAKKA-DAKKA!!!";
}

string TF2Heavy::attaqueProche() const
{
	return "Je n'ai besoin d'aucune arrrrme kamarade!  Mon poing est une arrrme de destrrruction massive!";
}

string TF2Heavy::bizou(TF2Medic* medic) const
{
	return "Ahhh! ça fait du bien: grrrôs câlin!\n" + medic->recevoirBizou();
}
