#pragma once

#include "TF2Perso.h"
//#include "TF2Heavy.h"
#include <string>

using std::string;

namespace TF2
{
	class TF2Heavy;   //DOIT ÊTRE DANS LE NAMESPACE VU QUE LA CLASSE ORIGINALE L'EST AUSSI

	class TF2Medic : public TF2Perso
	{
	public:
		TF2Medic();
		string attaqueDistance() const;
		string attaqueProche() const;
		string soignerHeavy(TF2Heavy* heavy);
		string recevoirBizou();
	};
}
