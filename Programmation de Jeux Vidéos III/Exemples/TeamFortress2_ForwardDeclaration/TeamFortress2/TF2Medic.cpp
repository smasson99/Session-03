#include "TF2Medic.h"
#include "TF2Heavy.h"

using namespace TF2;

TF2Medic::TF2Medic()
{
	health = 150;
	typePerso = "Medic";
}

string TF2Medic::attaqueDistance() const
{
	return "J� v� t� ffaire un� piquiure, �a n� v�ra pas mal!";
}

string TF2Medic::attaqueProche() const
{
	return "J� v� t� szier tous les membres, et �a, �a v�ra dr�s, dr�s mal!";
}

string TF2Medic::soignerHeavy(TF2Heavy* heavy)
{
	heavy->setHealth(heavy->getHealth() + 1);
	return "G� fous ai zoign�, herr patient!";
}

string TF2Medic::recevoirBizou()
{
	return "Danke, ich auch ich leibe dich!";
}
