#include "TF2Perso.h"
#include <string>

using std::string;

namespace TF2
{
	class TF2Scout : public TF2Perso 
	{
		public:
			TF2Scout();
			string attaqueDistance() const;
			string attaqueProche() const;
            string attaqueSournoise() const;
	};
}