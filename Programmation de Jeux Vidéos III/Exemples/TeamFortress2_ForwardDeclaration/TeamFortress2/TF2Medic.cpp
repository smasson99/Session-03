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
	return "Jé vé té ffaire uné piquiure, ça né véra pas mal!";
}

string TF2Medic::attaqueProche() const
{
	return "Jé vé té szier tous les membres, et ça, ça véra drès, drès mal!";
}

string TF2Medic::soignerHeavy(TF2Heavy* heavy)
{
	heavy->setHealth(heavy->getHealth() + 1);
	return "Gé fous ai zoigné, herr patient!";
}

string TF2Medic::recevoirBizou()
{
	return "Danke, ich auch ich leibe dich!";
}
