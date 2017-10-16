#pragma once
#include "SnackMcDo.h"

namespace Fabrique
{
	class FabriqueMcDo
	{
	public:
		static enum typeSnack { Burger, Gravy, Dessert };

		static SnackMcDo* createSnackMcDo(typeSnack commande)
		{
			if (Burger == commande)
			{
				return new BigMac();
			}
			else if (Gravy == commande)
			{
				return new Poutine();
			}
			else if (Dessert == commande)
			{
				return new McFlurry();
			}
			return nullptr;
		}
	private:
		FabriqueMcDo();
	};
}
