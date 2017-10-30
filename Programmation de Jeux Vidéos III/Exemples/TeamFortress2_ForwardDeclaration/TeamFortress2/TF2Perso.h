#pragma once

#include <string>

using std::string;

namespace TF2
{
	class TF2Perso 
	{
		public:
			TF2Perso();
			string getTypePerso() const;
			void setTypePerso(const string typePerso);
			int getHealth() const;
			void setHealth(const int health);
			string toString() const; 
			virtual string attaqueDistance() const = 0;
			virtual string attaqueProche() const = 0;

		protected:
			int health;
			string typePerso;
	};
}