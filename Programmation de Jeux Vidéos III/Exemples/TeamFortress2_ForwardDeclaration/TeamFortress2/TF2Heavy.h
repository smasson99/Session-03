#pragma once

#include "TF2Perso.h"
//#include "TF2Medic.h"
#include <string>

using std::string;

namespace TF2
{
	class TF2Medic; //DOIT ÊTRE DANS LE NAMESPACE VU QUE LA CLASSE ORIGINALE L'EST AUSSI

	class TF2Heavy : public TF2Perso
	{
	public:
		TF2Heavy();
		string attaqueDistance() const;
		string attaqueProche() const;
		string bizou(TF2Medic* medic) const;
	};
}