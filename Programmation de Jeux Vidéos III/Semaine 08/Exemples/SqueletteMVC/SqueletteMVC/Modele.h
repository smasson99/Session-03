#pragma once
#include <string>

using std::string;

namespace MVC
{
	class Modele
	{
	public:
		Modele();
		string salutations(const string& salutationRecue, int& pointsPolitesse);

	private:
		string politesses[3];

	};
}
