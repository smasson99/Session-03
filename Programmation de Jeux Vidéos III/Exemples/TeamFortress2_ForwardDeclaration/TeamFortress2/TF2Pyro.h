#pragma once

#include "TF2Perso.h"
#include <string>

using std::string;

namespace TF2
{
	class TF2Pyro : public TF2Perso 
	{
		public:
			TF2Pyro();
			string attaqueDistance() const;
			string attaqueProche() const;
	};
}