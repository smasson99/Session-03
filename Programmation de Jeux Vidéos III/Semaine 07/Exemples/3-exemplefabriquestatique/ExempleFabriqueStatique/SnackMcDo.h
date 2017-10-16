#pragma once
#include <string>

//Il est théoriquement possible de mettre plus d'une classe dans un .h
//C'est peu recommandé, mais pour des mini-classes comme ça, pourquoi pas.

namespace Fabrique
{
	class SnackMcDo
	{
	public:
		virtual std::string getSnack() = 0;
	};

	class BigMac : public SnackMcDo
	{
	public:
		std::string getSnack()
		{
			return "Un bon gros Big Mac";
		}
	};

	class Poutine : public SnackMcDo
	{
	public:
		std::string getSnack()
		{
			return "Poutine avec du fromage fondant";
		}
	};

	class McFlurry : public SnackMcDo
	{
	public:
		std::string getSnack()
		{
			return "Crème molle avec du... euh... du chimique... genre...";
		}
	};
}