#pragma once

#include "TF2Perso.h"
#include <string>

using std::string;

namespace TF2
{
	class TF2Sniper : public TF2Perso 
	{
		public:
			TF2Sniper();
			string attaqueDistance() const;
			string attaqueProche() const;
			string headshot() const;
	};
}